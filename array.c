#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

typedef int KEY_TYPE;

struct Arr{
	int capacity;
	int size;
	KEY_TYPE *data;
};

void init_array(struct Arr* a,int capacity){
	if(a==NULL)
		assert(0);
	a->data=(KEY_TYPE*)malloc(sizeof(KEY_TYPE)*capacity);
	if(a->data==NULL)
		printf("Dynamic memory allocation failed\n");
	a->capacity=capacity;
	a->size=0;
}

bool is_full_array(const struct Arr* a){
	if(a==NULL)
		assert(0);

	if(a->size==a->capacity)
		return true;

	return false;
}

bool is_empty_array(const struct Arr* a){
	if(a==NULL)
		assert(0);
		
	if(a->size==0)
		return true;
		
	return false;
}

void show_array(const struct Arr* a){
	if(a==NULL)
		assert(0);
	int i=0;		
	for(i=0;i<a->size;i++){
		printf("%4d",a->data[i]);
	}
	printf("\n");
}

int append_array(struct Arr* a,KEY_TYPE k){
	if(a==NULL)
		assert(0);

	if(is_full_array(a)){
		printf("The memory is full!\n");
		return -1;
	}

	a->data[a->size]=k;
	a->size++;
	return 0;
}

int insert_array(struct Arr* a,int pos,KEY_TYPE k){
	if(a==NULL)
		assert(0);

	if(is_full_array(a)){
		printf("The memory is full!\n");
		return -1;
	}

	int i=a->size;
	for(i=a->size;i>=pos;i--){
		a->data[i]=a->data[i-1];
	}
	a->data[pos-1]=k;
	a->size++;

	return 0;
}

int remove_data(struct Arr* a,int pos,int *val){
	if(a==NULL)
		assert(0);

	if(pos<1 || a->size<pos){
		printf("The deleted location is not valid!\n");
		return -1;
	}

	int i=pos-1;
	*val=a->data[pos-1];
	for(i=pos-1;i<a->size-1;i++){
		a->data[i]=a->data[i+1];
	}
	a->size--;

	printf("finished completing remove the data %4d\n",*val);

	return 0;
}	

int inverse(struct Arr* a){
	if(a==NULL)
		assert(0);
		
	if(is_empty_array(a)){
		printf("The data is empty!\n");
		return -1;
	}
	
	int begin=0;
	int end=a->size-1;
	
	while(begin<end){
		int temp=a->data[begin];
		a->data[begin]=a->data[end];
		a->data[end]=temp;
		
		begin++;
		end--;
	}
	
	return 0;
}

int main(){
	struct Arr p;

	init_array(&p,4);

	append_array(&p,3);
	append_array(&p,12);
	append_array(&p,15);

	show_array(&p);

	insert_array(&p,2,8);
	show_array(&p);

	int val;
	remove_data(&p,3,&val);
	show_array(&p);

	inverse(&p);
	show_array(&p);
	return 0;
}
