#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeString {
    char* value;
    struct NodeString* next;
} NodeString;

NodeString* createNodeString(const char* value);

void insertFirstString(NodeString** head, const char* value);
void insertLastString(NodeString** head, const char* value);
void insertBetweenBeforeString(NodeString** head, NodeString* targetNode, const char* value);
void insertBetweenAfterString(NodeString* targetNode, const char* value);
void insertValueBeforeString(NodeString** head, const char* targetValue, const char* value);
void insertValueAfterString(NodeString* head, const char* targetValue, const char* value);
void deleteFirstString(NodeString** head);
void deleteLastString(NodeString** head);
void deleteBetweenBeforeString(NodeString** head, NodeString* targetNode);
void deleteBetweenAfterString(NodeString* targetNode);
void deleteValueString(NodeString** head, const char* targetValue);
void deleteAllString(NodeString** head);
void modifyFirstString(NodeString* head, const char* newValue);
void modifyLastString(NodeString* head, const char* newValue);
void modifyValueString(NodeString* head, const char* oldValue, const char* newValue);
void modifyBetweenBeforeString(NodeString** head, NodeString* targetNode, const char* newValue);
void modifyBetweenAfterString(NodeString* targetNode, const char* newValue);

int countNodesString(NodeString* head);
NodeString* findNodeString(NodeString* head, const char* value);

#endif