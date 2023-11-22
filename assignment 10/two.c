#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a term in the polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node with given coefficient and exponent
struct Node* createNode(int coef, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coef;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial
void insertTerm(struct Node** poly, int coef, int exp) {
    struct Node* temp = createNode(coef, exp);
    temp->next = *poly;
    *poly = temp;
}

// Function to display a polynomial
void displayPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coef1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;

        int coef2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        int sum_coef = coef1 + coef2;
        insertTerm(&result, sum_coef, exp1);

        if (poly1 != NULL) {
            poly1 = poly1->next;
        }
        if (poly2 != NULL) {
            poly2 = poly2->next;
        }
    }
    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Input for the first polynomial
    int n, coef, exp;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents for each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        insertTerm(&poly1, coef, exp);
    }

    // Input for the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents for each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        insertTerm(&poly2, coef, exp);
    }

    // Add the polynomials and display the result
    result = addPolynomials(poly1, poly2);
    printf("Resultant polynomial after addition: ");
    displayPoly(result);

    return 0;
}
