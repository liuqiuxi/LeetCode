﻿#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 1000

typedef struct Node
{
	char *word;
	int times;
	struct Node *next;
}data;

int hash(char *word)
{
	int h = 0;
	for (int i = 0; word[i]; i++)
	{
		h = (h * 31 + word[i]) % SIZE;
	}
	return h;
}

int InsertMap(data **map, char *word, int lenw)
{
	int h = hash(word);
	if (map[h] == NULL){
		map[h] = (data*)malloc(sizeof(data));
		map[h]->word = (char*)malloc(sizeof(word[0]) * (lenw + 1));
		map[h]->times = 1;
		//strcpy(map[h]->word, word);
		strcpy_s(map[h]->word, sizeof(word[0]) * (lenw + 1), word);
		map[h]->next = NULL;
		return 1;
	}else {
		data *p = map[h];
		while (p->next)
		{
			if (strcmp(p->word, word) == 0){
				p->times++;
				return p->times;
			}
			p = p->next;
		}
		if (strcmp(p->word, word) == 0){
			p->times++;
			return p->times;
		}else {
			data *tmp = (data*)malloc(sizeof(data));
			tmp->word = (char*)malloc(sizeof(word[0]) * (lenw + 1));
			tmp->times = 1;
			//strcpy(tmp->word, word);
			strcpy_s(map[h]->word, sizeof(word[0]) * (lenw + 1), word);
			tmp->next = NULL;
			p->next = tmp;
			return 1;
		}
	}
}

int FindMap(data **map, char *sub)
{
	int h = hash(sub);
	if (map[h] == NULL){
		return -1;
	}else {
		data *p = map[h];
		while (p) {
			if (strcmp(p->word, sub) == 0) {
				return p->times;
			}
			p = p->next;
		}
		return -1;
	}
}

char* substring(char *s, int start, int len)
{
	char *sub = (char*)malloc(sizeof(char) * (len + 1));
	int i = 0;
	for (i; i < len; i++)
	{
		sub[i] = s[i + start];
	}
	sub[i] = 0;
	return sub;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
	if (*s == '\0' || wordsSize == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	int lenw = strlen(words[0]), lens = strlen(s), length = wordsSize;
	int *result = (int*)malloc(sizeof(int) * (lens - lenw * length + 1));
	data** map = (data**)malloc(sizeof(data*) * SIZE);
	data** tmp = (data**)malloc(sizeof(data*) * SIZE);
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		map[i] = NULL;
		tmp[i] = NULL;
	}
	for (i = 0; i < length; i++) InsertMap(map, words[i], (int)strlen(words[i]));
	*returnSize = 0;
	for (i = 0; i < lens - lenw * length + 1; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (tmp[j] != NULL)
			{
				free(tmp[j]);
				tmp[j] = NULL;
			}
		}
		for (j = 0; j < length; j++)
		{
			char *sub = substring(s, i + j * lenw, lenw);
			int mapnum = FindMap(map, sub);
			if (mapnum == -1) break;
			int num = InsertMap(tmp, sub, (int)strlen(sub));
			if (mapnum < num) break;
			free(sub);
		}
		if (j >= length) result[(*returnSize)++] = i;
	}
	for (i = 0; i < SIZE; i++) if (map[i] != NULL) free(map[i]);
	free(map);
	return result;
}

int main()
{
	int i;
	char s[] = "barfoothefoobarman";
	char *words[] = {"foo", "bar"};
	int *result = findSubstring(s, words, sizeof(words) / sizeof(char*), &i);
	for (int j = 0; j < i; j++) printf("%d", result[j]);
	return 0;
}