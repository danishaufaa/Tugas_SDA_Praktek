#include "linked_list.h"

NodeString* createNodeString(const char* value) {
    NodeString* newNode = (NodeString*)malloc(sizeof(NodeString));
    newNode->value = strdup(value);
    newNode->next = NULL;
    return newNode;
}

void insertFirstString(NodeString** head, const char* value) {
    NodeString* newNode = createNodeString(value);
    newNode->next = *head;
    *head = newNode;
}

void insertLastString(NodeString** head, const char* value) {
    NodeString* newNode = createNodeString(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    NodeString* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertBetweenBeforeString(NodeString** head, NodeString* targetNode, const char* value) {
    if (*head == NULL || targetNode == NULL) return;
    if (*head == targetNode) {
        insertFirstString(head, value);
        return;
    }
    NodeString* temp = *head;
    while (temp != NULL && temp->next != targetNode) {
        temp = temp->next;
    }
    if (temp != NULL) {
        NodeString* newNode = createNodeString(value);
        newNode->next = targetNode;
        temp->next = newNode;
    }
}

void insertBetweenAfterString(NodeString* targetNode, const char* value) {
    if (targetNode == NULL) return;
    NodeString* newNode = createNodeString(value);
    newNode->next = targetNode->next;
    targetNode->next = newNode;
}

void insertValueBeforeString(NodeString** head, const char* targetValue, const char* value) {
    NodeString* temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->value, targetValue) == 0) {
            insertBetweenBeforeString(head, temp, value);
            return;
        }
        temp = temp->next;
    }
}

void insertValueAfterString(NodeString* head, const char* targetValue, const char* value) {
    NodeString* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->value, targetValue) == 0) {
            insertBetweenAfterString(temp, value);
            return;
        }
        temp = temp->next;
    }
}

void deleteFirstString(NodeString** head) {
    if (*head == NULL) return;
    NodeString* temp = *head;
    *head = (*head)->next;
    free(temp->value);
    free(temp);
}

void deleteLastString(NodeString** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free((*head)->value);
        free(*head);
        *head = NULL;
        return;
    }
    NodeString* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next->value);
    free(temp->next);
    temp->next = NULL;
}

void deleteBetweenBeforeString(NodeString** head, NodeString* targetNode) {
    if (*head == NULL || targetNode == NULL || *head == targetNode) return;
    NodeString* temp = *head;
    while (temp->next != NULL && temp->next != targetNode) {
        temp = temp->next;
    }
    if (temp->next == targetNode) {
        NodeString* toDelete = temp;
        if (toDelete == *head) {
            deleteFirstString(head);
        } else {
            NodeString* prev = *head;
            while (prev->next != toDelete) {
                prev = prev->next;
            }
            prev->next = toDelete->next;
            free(toDelete->value);
            free(toDelete);
        }
    }
}

void deleteBetweenAfterString(NodeString* targetNode) {
    if (targetNode == NULL || targetNode->next == NULL) return;
    NodeString* temp = targetNode->next;
    targetNode->next = temp->next;
    free(temp->value);
    free(temp);
}

void deleteValueString(NodeString** head, const char* targetValue) {
    NodeString* temp = *head;
    NodeString* prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->value, targetValue) == 0) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp->value);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void deleteAllString(NodeString** head) {
    while (*head != NULL) {
        deleteFirstString(head);
    }
}

void modifyFirstString(NodeString* head, const char* newValue) {
    if (head == NULL) return;
    free(head->value);
    head->value = strdup(newValue);
}

void modifyLastString(NodeString* head, const char* newValue) {
    if (head == NULL) return;
    while (head->next != NULL) {
        head = head->next;
    }
    free(head->value);
    head->value = strdup(newValue);
}
