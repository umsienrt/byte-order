#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

int main(int num, char* bin_list[]){
	uint32_t n = 0;
	uint32_t h[num];
	uint32_t sum = 0;

	for(int i=1; i<num; i++){
		FILE* fp = fopen(bin_list[i],"rb");
		if(fp != NULL){
			size_t s = fread(&n, sizeof(uint32_t), 1, fp);
			if(s != 1){
				printf("error: requires a 4byte file");
				fclose(fp);
				return -1;
			}else{
				h[i] = ntohl(n);
				sum += h[i];
				fclose(fp);
			}	
		}else{
			printf("error: no file");
			return -1;
		}
	}

	for(int i=1; i<num; i++){
		printf("%u(0x%08x)", h[i], h[i]);
		if(i < num-1){
			printf(" + ");
		}else{
			printf(" = ");
		}
	}
	printf("%u(0x%08x)", sum, sum);
	return 0;

}
