#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

int choice, admin_choice;

int hotel_id, reg_id;
   int room_choice;
   int nights;
int charge_per_night;
int total_bill;


    int count;
    int found;

   int file_id, file_room, file_nights, file_bill;

int admin_pass = 4567;   
int input_pass, encrypted_input;

    char name[50];
   char phone[20];
   char marital_status[15];
 char cnic[20];

int last_registered_id = 0; 
    char last_name[50];
    char last_phone[20];

    FILE *fp;

    srand(time(NULL));  

    do {
        printf("\n--- HOTEL MANAGEMENT SYSTEM ---\n");
        printf("1. Register Yourself as a New Tenant\n");
        printf("2. Book Room for Tenant\n");
        printf("3. Admin Page\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

       
        if (choice == 1) {

            printf("Enter Full Name: ");
            scanf(" %[^\n]", name);

            printf("Enter Phone Number: ");
            scanf(" %[^\n]", phone);

            printf("Enter Marital Status: ");
            scanf(" %[^\n]", marital_status);

            printf("Enter CNIC Number: ");
            scanf(" %[^\n]", cnic);

            hotel_id = rand() % 9000 + 1000;
            last_registered_id = hotel_id;  // save ID for immediate booking
            strcpy(last_name, name);
            strcpy(last_phone, phone);

            printf("\nYour Generated Hotel ID is: %d\n", hotel_id);
            printf("Please save this ID for booking.\n");

            fp = fopen("registration.txt", "a");
            if (fp != NULL) {
                fprintf(fp, "%d | %s | %s | %s | %s\n",
                        hotel_id, name, phone, marital_status, cnic);
                fclose(fp);
                printf("Registration successful.\n");
            } else {
                printf("Error saving registration data.\n");
            }
        }

       
        else if (choice == 2) {

            printf("Enter your Hotel ID: ");
            scanf("%d", &hotel_id);

            
            found = 0;
            char tenant_name[50] = "";
            char tenant_phone[20] = "";

           
            if (hotel_id == last_registered_id) {
                found = 1;
                strcpy(tenant_name, last_name);
                strcpy(tenant_phone, last_phone);
            }

           
            if (!found) {
                fp = fopen("registration.txt", "r");
                if (fp != NULL) {
                    char line[200];
                    while (fgets(line, sizeof(line), fp) != NULL) {
                        int file_id;
                        char file_name[50], file_phone[20], file_marital[15], file_cnic[20];
                        if (sscanf(line, "%d | %49[^|] | %19[^|] | %14[^|] | %19s",
                                   &file_id, file_name, file_phone, file_marital, file_cnic) == 5) {
                            if (file_id == hotel_id) {
                                found = 1;
                                strcpy(tenant_name, file_name);
                                strcpy(tenant_phone, file_phone);
                                break;
                            }
                        }
                    }
                    fclose(fp);
                }
            }

            if (!found) {
                printf("Hotel ID not found. Please register first.\n");
                continue;
            }

            
            printf("\nSelect Room Type:\n");
            printf("1. Single Bed ($50 per night)\n");
            printf("2. Double Bed ($100 per night)\n");
            printf("3. Suite Room ($200 per night)\n");
            printf("Enter room choice: ");
            scanf("%d", &room_choice);

            if (room_choice == 1)
                charge_per_night = 50;
            else if (room_choice == 2)
                charge_per_night = 100;
            else if (room_choice == 3)
                charge_per_night = 200;
            else {
                printf("Invalid room choice.\n");
                continue;
            }

            printf("Enter number of nights: ");
            scanf("%d", &nights);

            total_bill = charge_per_night * nights;

            
            printf("\nTotal Bill: $%d\n", total_bill);
            printf("Kindly pay your bill to confirm booking.\n");

            // Assign a random room number
            int room_number = rand() % 900 + 100;

            
            fp = fopen("tenants.txt", "a");
            if (fp != NULL) {
                fprintf(fp, "%d %d %d %d\n",
                        hotel_id, room_choice, nights, total_bill);
                fclose(fp);
            } else {
                printf("Error saving booking data.\n");
                continue;
            }

           
            printf("\n--- BOOKING SUMMARY ---\n");
            printf("Name: %s\n", tenant_name);
            printf("Contact Number: %s\n", tenant_phone);
            printf("Room Number Allotted: %d\n", room_number);
            if (room_choice == 1)
                printf("Room Type: Single Bed\n");
            else if (room_choice == 2)
                printf("Room Type: Double Bed\n");
            else
                printf("Room Type: Suite Room\n");
            printf("Total Bill Paid: $%d\n", total_bill);

        }

        else if (choice == 3) {

            printf("Enter Admin Password: ");
            scanf("%d", &input_pass);

            encrypted_input = input_pass + 3333;

            if (encrypted_input != admin_pass) {
                printf("Access Denied.\n");
                continue;
            }

            printf("Access Granted.\n");

            do {
                printf("\n--- ADMIN PANEL ---\n");
                printf("1. Number of people staying\n");
                printf("2. Total rooms booked\n");
                printf("3. Tenants information\n");
                printf("4. Back to Main Menu\n");
                printf("Enter choice: ");
                scanf("%d", &admin_choice);

                if (admin_choice == 1 || admin_choice == 2) {

                    fp = fopen("tenants.txt", "r");
                    count = 0;

                    if (fp != NULL) {
                        while (fscanf(fp, "%d %d %d %d",
                                       &file_id, &file_room,
                                       &file_nights, &file_bill) != EOF) {
                            count++;
                        }
                        fclose(fp);
                    }

                    if (admin_choice == 1)
                        printf("Total people staying: %d\n", count);
                    else
                        printf("Total rooms booked: %d\n", count);
                }

                else if (admin_choice == 3) {

                    fp = fopen("tenants.txt", "r");

                    if (fp != NULL) {
                        printf("\n--- TENANTS DETAILS ---\n");

                        while (fscanf(fp, "%d %d %d %d",
                                       &file_id, &file_room,
                                       &file_nights, &file_bill) != EOF) {

                            printf("Hotel ID: %d\n", file_id);

                            if (file_room == 1)
                                printf("Room Type: Single Bed\n");
                            else if (file_room == 2)
                                printf("Room Type: Double Bed\n");
                            else
                                printf("Room Type: Suite Room\n");

                            printf("Nights Stayed: %d\n", file_nights);
                            printf("Total Bill: $%d\n\n", file_bill);
                        }
                        fclose(fp);
                    }
                }

            } while (admin_choice != 4);
        }

        else if (choice == 4) {
            printf("Exiting program...\n");
        }

        else {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    getchar();
    getchar();
    return 0;
}