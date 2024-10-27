/* We need a Parking allotment, Vehicle Exit, Amount received */
/* Parking Allotment : 
Let's take 1-10 for Cars, 11-20 for Auto, 21-30 for Bikes */
/* Vehicle Exit : 
When the vehicle is removed, the amount is calculated */
/* Amount received :
The amount is calculated based on the vehicle type */

#include <stdio.h>
#include <stdlib.h>

int noc = 0; // Number of occupied slots
int amt = 0; // Amount collected
int car_slots[10] = {0}; // Slots for Cars (1-10)
int auto_slots[10] = {0}; // Slots for Auto (11-20)
int bike_slots[10] = {0}; // Slots for Bikes (21-30)

// Parking Allotment
void parkVehicle(int type) {
    int *slots;
    int slot_count;

    switch (type) {
        case 1: // Cars
            slots = car_slots;
            slot_count = 10;
            break;
        case 2: // Auto
            slots = auto_slots;
            slot_count = 10;
            break;
        case 3: // Bikes
            slots = bike_slots;
            slot_count = 10;
            break;
        default:
            printf("Invalid vehicle type.\n");
            return;
    }

    for (int tno = 0; tno < slot_count; tno++) {
        if (slots[tno] == 0) { // If slot is free
            slots[tno] = 1; // Mark as occupied
            noc++;
            printf("Parking Allotted for %s is %d\n", (type == 1) ? "Car" : (type == 2) ? "Auto" : "Bike", tno + 1 + (type - 1) * 10);
            return;
        }
    }
    printf("Parking Full for %s\n", (type == 1) ? "Cars" : (type == 2) ? "Auto" : "Bikes");
}

// Vehicle Exit
void vehicleExit(int type) {
    int slot_number;

    printf("Enter the Slot Number\n");
    scanf("%d", &slot_number);
    int index = slot_number - 1; // Convert to zero-based index

    if (type == 1 && index < 0 || index >= 10) {
        printf("Invalid Slot Number for Cars\n");
        return;
    }
    if (type == 2 && (index < 10 || index >= 20)) {
        printf("Invalid Slot Number for Auto\n");
        return;
    }
    if (type == 3 && (index < 20 || index >= 30)) {
        printf("Invalid Slot Number for Bikes\n");
        return;
    }

    if (type == 1 && car_slots[index] == 0) {
        printf("Slot is already free.\n");
        return;
    }
    if (type == 2 && auto_slots[index - 10] == 0) {
        printf("Slot is already free.\n");
        return;
    }
    if (type == 3 && bike_slots[index - 20] == 0) {
        printf("Slot is already free.\n");
        return;
    }

    // Mark slot as free
    if (type == 1) {
        car_slots[index] = 0;
        amt += 20;
    } else if (type == 2) {
        auto_slots[index - 10] = 0;
        amt += 10;
    } else if (type == 3) {
        bike_slots[index - 20] = 0;
        amt += 5;
    }
    
    noc--;
    printf("Vehicle Exited from Slot Number %d\n", slot_number);
}

// Amount Received
void amountReceived() {
    printf("Amount Received is %d\n", amt);
}

int main() {
    int ch;
    while (1) {
        printf("1. Parking Allotment\n");
        printf("2. Vehicle Exit\n");
        printf("3. Amount Received\n");
        printf("4. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: {
                printf("1. Cars\n");
                printf("2. Auto\n");
                printf("3. Bikes\n");
                printf("Enter your choice\n");
                scanf("%d", &ch);
                parkVehicle(ch);
                break;
            }
            case 2: {
                printf("1. Cars\n");
                printf("2. Auto\n");
                printf("3. Bikes\n");
                printf("Enter your choice\n");
                scanf("%d", &ch);
                vehicleExit(ch);
                break;
            }
            case 3:
                amountReceived();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
