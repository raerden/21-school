#!/bin/bash

FileName=$1
SearchText=$2
ReplaceText=$3
Errors=0



if [ ! -f "$FileName" ]; then
    echo "Файл $FileName не существует"
    Errors=1
fi

if [ "$SearchText" == "" ]; then
    echo "Не указан текст для поиска"
    Errors=1
fi

if [ "$ReplaceText" == "" ]; then
    echo "Не указан текст для для замены"
    Errors=1
fi

if [ "$Errors" == 1 ]; then
    echo "Использование программы:"
    echo "edit.sh FileName SearchText ReplaceText"
    exit
fi

#выполнил замену текста в файле с перезаписью файла. Ключ -i
sed -i '' "s/$SearchText/$ReplaceText/g" $FileName

#обрезать всю строку до последнего слеша
FPath=${PWD##*/}/$(basename $FileName)

FSize=$(stat -f %z $FileName)
FDate=$(stat -f %Sm $FileName | date '+%Y-%m-%d %H:%M')
FSha256=$(shasum -a 256 $FileName | awk '{print $1}')

#дополняем файл лога новой записью 
echo "$FPath - $FSize - $FDate - $FSha256 - sha256" >> files.log

