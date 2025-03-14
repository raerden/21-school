#!/bin/bash

FileName=$1

#Проверка на существование файла лога
if [ ! -f "$FileName" ]; then
    echo "Файл $FileName не существует"
    exit
fi

#Проверка корректности лога 
#по разделителю ' - ' В строке их должно быть 4
#Читаем файл построчно
while IFS= read -r line; do
   divcount=$(echo $line | grep -o ' - ' | wc -l) #проверяю количество разделителей ' - ' их должно быть 4
   if [ $divcount != 4 ];  then 
        echo "Не корректный формат лога"
        exit
    fi
done < "$FileName"

RecordsCount=$(wc -l $FileName | awk '{print $1}')
UniqueFilesCount=$(awk '{print $1}' $FileName | sort -u | wc -l) 
EditsCount=$(cat $FileName | awk '{print $8}'| sort -u | wc -l)



echo "$RecordsCount $UniqueFilesCount $EditsCount"
