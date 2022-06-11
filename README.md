<h1 align="left"><img src="figures/logo.jpg" width="40" alt="Sudoku Solver" v/> Sudoku Solver</h1>
Данная программа предназначена для решения головоломок судоку. На данный момент алгоритм способен решать лишь несложные головоломки, что автор в будущем планирует исправить.
<h3>Требования</h3>

- linux-headers 5.10.0 или новее
- GLIBC 2.27 или новее
- GCC 7.5.0 или новее
- GNU Make 4.1 или новее

<h3>Сборка из исходных файлов</h3>
Открыть командную оболочку (shell) и выполнить указанные команды:

```bash
git clone https://github.com/VasiliyMatlab/Sudoku.git
cd Sudoku
```
Следующим шагом является сборка проекта с помощью утилиты `make`:
```bash
cd src/
make
cd ../bin/
ls
```
После выполнения указанных действий в списке содержимого папки `bin/` должены появиться файл `sudoku.elf`. Если данный файл в результате выполнения указанных действий не был создан - обратитесь к автору данной программы

<h3>Скачивание бинарных файлов</h3>
Необходимо скачать <a href="https://github.com/VasiliyMatlab/Sudoku/releases/latest/download/Binaries.tar.gz">архив</a> с бинарными файлами (только для x86-64) из последнего доступного <a href="https://github.com/VasiliyMatlab/Sudoku/releases/latest">релиза</a> себе на диск и выполнить указанные действия:

```bash
tar -xvf Binaries.tar.gz
ls
```
Убедиться, что после выполнения указанных действий в текущей директории находится файл `sudoku.elf`. Если данный файл в результате выполнения указанных действий не найден - обратитесь к автору данной программы

<h3>Использование</h3>

```bash
./sudoku file1.txt file2.dan
```
При данном использовании программа пытается решить судоку, содержащиеся в указанных файлах (он может быть как один, так и несколько). Результаты попыток решения головоломки (удачные и не очень) программа выводит в консоль.
<h5>Дополнительные команды</h5>

Запросить справку по программе:
```bash
./sudoku --help
```
Запросить версию программы:
```bash
./sudoku --version
```
Использование данных опций вместе со входными файлами данных запрещено!
***
<p align="center"><a href="https://github.com/VasiliyMatlab"><img src="https://github.com/VasiliyMatlab.png" width="100" alt="VasiliyMatlab" /></a></p>
<p align="center"><a href="https://github.com/VasiliyMatlab" style="color: #000000">VasiliyMatlab</a></p>
