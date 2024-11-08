#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CAPTCHA_LENGTH 6
struct Node {
char data;
struct Node* next;
};
char generateRandomChar() {
const char charset[] =
"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const size_t max_index = (sizeof(charset) - 1);
return charset[rand() % max_index];
}
struct Node* createNode(char data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
newNode->data = data;
newNode->next = NULL;
return newNode;
}
struct Node* generateCaptcha() {
struct Node* head = NULL;
struct Node* tail = NULL;
srand(time(NULL));
for (int i = 0; i < CAPTCHA_LENGTH; ++i) {
char randomChar = generateRandomChar();
struct Node* newNode = createNode(randomChar);
if (head == NULL) {
head = tail = newNode;
} else {
tail->next = newNode;
tail = newNode;
}
}
return head;
}
void displayCaptcha(struct Node* head) {
struct Node* current = head;
while (current != NULL) {
printf("%c", current->data);
current = current->next;
}
printf("\n");
}
void freeLinkedList(struct Node* head) {
struct Node* current = head;
struct Node* next;
while (current != NULL) {
next = current->next;
free(current);
current = next;
}
}
int main() {
struct Node* captcha = generateCaptcha();
printf("Generated CAPTCHA: ");
displayCaptcha(captcha);
freeLinkedList(captcha);
return 0;
}
