#include <stdio.h>
#include <stdlib.h>

struct door
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};

int get_file_size_in_bytes(FILE *pfile)
{
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

struct door read_record_from_file(FILE *pfile, int index)
{
    int offset = index * sizeof(struct door);
    fseek(pfile, offset, SEEK_SET);
    struct door record;
    fread(&record, sizeof(struct door), 1, pfile);
    rewind(pfile);
    return record;
}

int main()
{
    //struct door *doors[10];
    FILE *ff = fopen("../datasets/door_state_1", "rb");
    if (ff == NULL) { printf("Can't open file\n");
    } else {
        int file_size = get_file_size_in_bytes(ff);
        printf("File size: %d\n", file_size);
        int rows = file_size / sizeof(struct door);
        printf("Rows: %d\n", rows);

        struct door *doors = malloc(rows * sizeof(struct door)); 
        
        
        if (doors)
            free(doors);
        fclose(ff); 
    }
    return 0;
}
