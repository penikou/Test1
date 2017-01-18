


#include <stdio.h>
#include <stdlib.h>


#define NAMESIZE 21


typedef struct listnode {
    
    int data;
    char firstname[NAMESIZE];
    char lastname[NAMESIZE];
    struct listnode *next;
    
    
}Listnode;


typedef struct list {
    
    Listnode *first;
    Listnode *last;
    
    
}List;

void insert(List *sp);
int delete(List *sp);
void instructions(void);
void printList(List *sp);



int main (int argc, const char * argv[]) {

    
    List mylist = {NULL, NULL};
    List *start_node = &mylist;
    
    
    
    int choice;
    
    instructions();
    printf("Enter your choice: \n");
    scanf("%d", &choice);
    
    while ( choice !=3 ) {
        
        switch(choice) {
                
                
            case 1:
                insert(start_node);
                printList(start_node);
                break;
                    
                
            case 2:
                delete(start_node);
                printList(start_node);
                break;    
                
            default :
                printf("Invalid choice: \n");
                break;

        
        
        }
        
        
        printf("Enter your choice: \n");
        instructions();
        scanf("%d", &choice);
        
        
        
        
        
    }
    
    
    printf("End of run. \n");
    
    return 0;
}




void insert(List *sp) {
    
    Listnode *new_node;
    Listnode *curr;
    Listnode *prev;
    
    
    
    
    new_node = (Listnode*)malloc(sizeof(Listnode));
    
    if(new_node!=NULL) {
    
    
    printf("Enter an integer: \n");
    scanf("%d", &new_node->data);
    
    
    
        
    prev = NULL;
    curr = sp->first;
    
    while(curr!=NULL && new_node->data>curr->data) {
            prev = curr;
            curr = curr->next;
            
            
    }
    
    
    if(sp->first == NULL) {
        new_node->next = sp->first;
        sp->first = new_node;
        sp->last = new_node;
        sp->last->next = NULL;
        
        
    }
               
        
    else if(curr == sp->first) {
        new_node->next = sp->first;
        sp->first = new_node;
    
    }
            else if(curr == sp->last) {
                sp->last = new_node;
                sp->last->next = NULL;
        
        
        
            }


                    else {
                        prev->next = new_node;
                        new_node->next = curr;
            
                    }
        
    
    }
                
            
            
    
    
    

}

void instructions(void) {
    
    
    printf("1. To insert an element into the list \n"
           "2. To delete an element from the list \n"
           "3. To end \n");
    
    
}


void printList(List *sp) {
    
    
    
    Listnode *curr;
    
    curr = sp->first;
    
    printf("hi\n");
    /*if(curr == NULL) {
        printf("List is empty. \n");
    }
    */
        
            while(curr!=NULL) {
                
                printf("%d --> ", curr->data);
                curr = curr->next;
            }
                
                printf("\n\n");
        
        
        
    
}



int delete(List *sp) {
    
    Listnode *curr, *temp, *prev;
    int number;
    
    
    if(curr ==NULL) {
        printf("List is empty. \n");
        return 0;
    }
    
    printf("Enter a number to be deleted: \n");
    scanf("%d", &number);
    
    
    
    
    if(sp->first->data == number) {
        
        temp = sp->first;
        sp->first = sp->first->next;
        free(temp);
        return number;
    }
    
            else {
                prev = sp->first;
                curr = sp->first->next;
                
                while(curr != NULL && curr->data != number) {
                    
                    prev = curr;
                    curr = curr->next;
                }
                
                
                if(curr!=NULL) {
                    
                    temp = curr;
                    prev->next = curr->next;
                    free(temp);
                    return number;
                    
                }
                
            }
                
    
    
    printf("Number not found. \n\n");
    return 0;
    
}
