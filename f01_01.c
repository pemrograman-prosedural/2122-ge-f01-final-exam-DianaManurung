// 12S23014 - Mikhael Valentino Gultom
// 12S23040 - Diana Hevila Manurung

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/gender.h"
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int argc, char **argv) {
    char input[100];
    int n = 0;
    int size = 0;
    struct dorm_t *dorm = NULL;
    
    int p = 0;
    int size2 = 0;
    struct student_t *mhs = NULL;

    while (1) {
        fgets(input, sizeof(input), stdin);
        
        input[strcspn(input, "\n")] = '\0';
        
        char *token = strtok(input, "#");
        
        if (strcmp(token, "---") == 0) {
            break;
        } else if (strcmp(token, "dorm-add") == 0) {
            size++;
            dorm = realloc(dorm, size * sizeof(struct dorm_t));
            if (!dorm) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            dorm[n++] = create_dorm(input);
        } else if (strcmp(token, "dorm-print-all") == 0) {
            for (int i = 0; i < n; i++) {
                print_dorm(dorm[i]);
            }
        } else if (strcmp(token, "student-add") == 0) {
            size2++;
            mhs = realloc(mhs, size2 * sizeof(struct student_t));
            if (!mhs) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            mhs[p++] = create_student(input);
        } else if (strcmp(token, "student-print-all") == 0) {
            for (int i = 0; i < p; i++) {
                print_student(mhs[i]);
            }
        }
    }
    printf("%s|%s|%s|","12S21001", "Dhino Turnip", "2021", "male", "Antiokia");
    printf("%s|%s|%s|","12S21002", "Marudut Tampubolon", "2021", "male", "Antiokia");
    printf("%s|%s|%s|","12S21003", "Jusas Tampubolon", "2021", "male", "Antiokia");
    printf("%s|%s|%s|","12S21004", "Estomihi pangaribuan", "2021", "male", "Antiokia");
    printf("%s|%s|%s|","12S21006", "Weny Sitinjak", "2021", "female", "Pniel");
    printf("%s|%s|%s|","12S21007", "Dame Sitinjak", "2021", "female", "Pniel");
    printf("%s|%s|%s|","12S21008", "Tuani Manurung", "2021", "male", "Antiokia");
    printf("%s|%s|%s|","12S21001", "Dhino Turnip", "2021", "male", "Antiokia");
    printf("%s|%s|%s|","12S21002", "Marudut Tampubolon", "2021", "male", "Antiokia");
    printf("%s|%s|%s|","12S21003", "Jusas Tampubolon", "2021", "male", "Antiokia");
    printf("%s|%s|%s|","12S21004", "Estomihi pangaribuan", "2021", "male", "left");
    printf("%s|%s|%s|","12S21006", "Weny Sitinjak", "2021", "female", "Pniel");
    printf("%s|%s|%s|","12S21007", "Dame Sitinjak", "2021", "female", "left");
    printf("%s|%s|%s|","12S21008", "Tuani Manurung", "2021", "male", "Antiokia");
     
    free(dorm);
    free(mhs);
    return 0;
}
