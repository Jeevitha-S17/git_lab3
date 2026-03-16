#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 // Define the maximum size of the queue

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function prototypes
void enqueue(int data);
int dequeue();
void display();
int isEmpty();
int isFull();

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    display();

    printf("\nDequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    
    display();
    
    enqueue(50);
    enqueue(60); // This will show the queue is full

    display();

    return 0;
}

// Check if the queue is empty
int isEmpty() {
    // A queue is empty if both front and rear are -1, or if front has moved past the rear
    if (front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

// Check if the queue is full
int isFull() {
    // A queue is full if the rear has reached the maximum size of the array
    if (rear == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

// Add an element to the rear of the queue
void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow: Cannot enqueue element %d\n", data);
        return;
    }
    if (isEmpty()) {
        front = 0; // Set front to 0 when the first element is enqueued
    }
    rear++;
    queue[rear] = data;
    printf("Enqueued %d\n", data);
}

// Remove an element from the front of the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow: Cannot dequeue element\n");
        return -1; // Return an error value
    }
    int data = queue[front];
    if (front == rear) {
        // If the last element is dequeued, reset front and rear
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return data;
}
int peek() {
    if (isEmpty()) {
        printf("Queue is empty.\\n");
        return -1;
    }
    return queue_array[front];
}


// Display the elements in the queue
void display() {
    if (isEmpty()) {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
