#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int countRemainingLetters(const char *name1, const char *name2) {
    int count1[26] = {0};
    int count2[26] = {0};
    int total = 0;
    int i;
    
    for (i = 0; name1[i]; i++) {
        count1[tolower(name1[i]) - 'a']++; 
    }
    
    for (i = 0; name2[i]; i++) {
        count2[tolower(name2[i]) - 'a']++;
    }
    
    for (i = 0; i < 26; i++) {
        total += abs(count1[i] - count2[i]);
    }
    
    return total;
}

const char *getFlamesResult(int count) {
    static const char *results[] = {
        "Friends",
        "Lovers",
        "Adversaries",
        "Married",
        "Enemies",
        "Sweethearts"
    };
    
    if (count == 0) return results[0];
    
    return results[(count - 1) % 6];
}

int main() {
    char maleName[50];
    char femaleName[50];
    
    printf("Enter the first name: ");
    fgets(maleName, 50, stdin);
    maleName[strcspn(maleName, "\n")] = '\0';
    
    printf("Enter the second name: ");
    fgets(femaleName, 50, stdin);
    femaleName[strcspn(femaleName, "\n")] = '\0';
    
    int remaining = countRemainingLetters(maleName, femaleName);
    
    const char *result = getFlamesResult(remaining);
    
    printf("The relationship status between %s and %s is: %s\n", maleName, femaleName, result);
    
    return 0;
}