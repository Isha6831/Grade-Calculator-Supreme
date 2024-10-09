#include <stdio.h>

void read_marks(const char* subject, float* mark) {
    do {
        printf("Enter the Marks of %s in Sem-I (0-100): ", subject);
        scanf("%f", mark);
        if (*mark < 0 || *mark > 100) {
            printf("Invalid input! Marks must be between 0 and 100.\n");
        }
    } while (*mark < 0 || *mark > 100);
}

int main() {
    int num; // Number of students
    float math, chem, phy, eng, cs, average, cie;
    float totalAverage = 0; // Total average for the batch
    float totalMath = 0, totalChem = 0, totalPhy = 0, totalEng = 0, totalCs = 0; // Total marks for each subject
    int validStudents = 0;  // Count of eligible students

    printf("\nAverage Marks & Grade Calculator for Semester I");

    printf("\nNumber of Students in Batch: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("\n\nFor Student %d:\n", i + 1);
        
        // Enter and validate CIE marks
        printf("Enter the CIE for Student %d (0-100): ", i + 1);
        scanf("%f", &cie);
        if (cie < 0 || cie > 100) {
            printf("Invalid CIE input! CIE must be between 0 and 100.\n");
            i--;  // Repeats current student's entry due to invalid input
            continue;
        } else if (cie < 75) {
            printf("CIE is less than 75. You are not eligible. Better luck next time!\n");
            continue; // Skip to the next student
        }

        // If CIE is valid, proceed to enter marks for the subjects
        printf("\nEnter the Marks for Student %d: \n", i + 1);
        read_marks("Mathematics", &math);
        read_marks("Chemistry", &chem);
        read_marks("Physics", &phy);
        read_marks("English", &eng);
        read_marks("Computer Science", &cs);

        average = (math + chem + phy + eng + cs) / 5;
        printf("\nStudent %d's Percentage is %.2f", i + 1, average);

        // Increment total average and valid student count
        totalAverage += average;
        validStudents++;

        // Add to subject totals
        totalMath += math;
        totalChem += chem;
        totalPhy += phy;
        totalEng += eng;
        totalCs += cs;

        // Checking passing criteria
        if (math < 45 && chem < 45 && phy < 45 && eng < 45 && cs < 45) {
            printf("\nSince the student does not meet the Passing Criterion, YOU ARE FAILED, better luck next time!");
            printf("\nAll the best for the next attempt!");
        } else {
            if (average >= 75) {
                printf("\nThe student has bagged Distinction");
            } else if (average >= 65) {
                printf("\nThe student has bagged First Class");
            } else if (average >= 55) {
                printf("\nThe student has bagged Second Class");
            } else if (average >= 45) {
                printf("\nThe student has bagged Third Class");
            }
        }
    }

    // Calculate and print the average percentage of the batch
    if (validStudents > 0) {
        float batchAverage = totalAverage / validStudents;
        printf("\n\nThe average percentage of the batch is: %.2f\n", batchAverage);

        // Calculate and print the average marks for each subject
        printf("\nAverage Marks for each subject:\n");
        printf("Mathematics: %.2f\n", totalMath / validStudents);
        printf("Chemistry: %.2f\n", totalChem / validStudents);
        printf("Physics: %.2f\n", totalPhy / validStudents);
        printf("English: %.2f\n", totalEng / validStudents);
        printf("Computer Science: %.2f\n", totalCs / validStudents);
    } else {
        printf("\nNo valid students to calculate batch average.\n");
    }

    return 0;
}
