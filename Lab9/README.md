# -Programming-course
Лаба №9 на 3
![alt text](Scrin/image.png)
С помощью git status узнал, что нахожусь на ветке main. git log выводит журнал коммитов в репозитории.
![alt text](Scrin/image-1.png)
Создал файл sort.c
![alt text](Scrin/image-2.png)
sort.c  не добавлен
![alt text](Scrin/image-3.png)
Добавил sort.c, о чём говорит git status
![alt text](Scrin/image-4.png)
Сделал commit, о чём говорит git status
![alt text](Scrin/image-5.png)
Добавил комментарий в файл sort.c, git status говорит что файл изменён, но изменение не добавлено, что далее я исправляю.
![alt text](Scrin/image-6.png)
Изменил файл, но не добавил изменения, о чем говорит git status
![alt text](Scrin/image-7.png)
Добавил изменения, закоммител и запушил на удаленный репозиторий. 
![alt text](Scrin/image-8.png)
Создал новую ветку, проверил на какой ветке нахожусь, переключил на созданную ветку, git status говорит, что я нахожусь на ветке mybranch и она пуста. git branch говорит, что нахожусь на новой ветке
![alt text](Scrin/image-9.png)
Создал file1.txt добавил его в stage, закоммитил, git log --oneline –graph говорит, что коммит сделан в ветке mybranch
![alt text](Scrin/image-10.png)
Переключился на ветку main, git log --oneline –graph показывет коммиты, сделанные на текущей ветке
![alt text](Scrin/image-11.png)
Создал file2.txt, добавил и закоммитил его. 
![alt text](Scrin/image-12.png)
Лаба №9 на 4
![alt text](Scrin/image-13.png)
Переключил на ветку main. git diff показывает изменения в файле. 
![alt text](Scrin/image-14.png)
![alt text](Scrin/image-15.png)
git sdiff –staged показывает разность между добавленными изменениями и последним коммитом.
![alt text](Scrin/image-16.png)
git diff показывает разницу между изменениями и тем, что добавлено в stage.
git sdiff –staged показывает разность между добавленными изменениями и последним коммитом (Так как не добавил текущие изменеия, то показывает изменеия с предыдущего пункта). 
![alt text](Scrin/image-17.png)
git restore --staged sort.c удаляет добавленные изменеия из stage.
![alt text](Scrin/image-18.png)
![alt text](Scrin/image-19.png)
git restore sort.c отменил все локальные изменения.
![alt text](Scrin/image-20.png)
![alt text](Scrin/image-21.png)
Git status говорит, что я нахожусь в ветке feature/uppercase и коммитов на этой ветке ещё не было. 
![alt text](Scrin/image-22.png)
Git branch показывает, что я нахожусь на ветке feature/uppercase. git log --oneline --graph --all строит график коммитов на всех ветках.
![alt text](Scrin/image-23.png)
![alt text](Scrin/image-24.png)
Объединил ветки main и feature/uppercase, после чего удалил ветку feature/uppercase.
![alt text](Scrin/image-25.png)
Смержил ветки main und mybranch. Команда git log --oneline --graph --all выводит графическое представление истории всех веток репозитория в компактном формате.