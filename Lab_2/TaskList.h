make Worker				main class											+
make Validator			for wrong file way									+
make Reader, Writer															+
make Operations			operations											+
/*>
readfile <filename>  Ц считывание текстового файла в пам€ть, целиком.¬ход Ц отсутствует, выход Ц текст.

writefile <filename> Ц запись текста в файл.¬ход Ц текст, выход Ц отсутствует.

grep <word> Ц выбор из входного текста строк, разделенных символами переноса строки, содержащих заданное слово <word>.¬ход Ц текст, выход Ц текст.

sort Ц лексикографическа€ сортировка входного набора строк.¬ход Ц текст, выход Ц текст.

replace <word1> <word2> Ц замена слова <word1> словом <word2> во входном тексте.¬ход Ц текст, выход Ц текст.

dump <filename> -сохранить пришедший текст в указанном файле и передать дальше.¬ход Ц текст, выход Ц текст.
<*/
BlokProgram																	+

make Parser				main part, part where hapend magic					+

ошибки работают не коректно													+
static void writeFile(string, vector<string>&);
static void readFile(string, vector<string>&);
/*void FileWriterBlock::writeFile(string output, vector<string>& text) ///////////////
{
    ofstream fos(output);

    if (!fos)
        Validator::badFile("File " + output + " cannot opened!");

    for (const auto& i : text)
        fos << i << endl;

    fos.close();
}

void FileReaderBlock::readFile(string input, vector<string>& output)
{
    /*if (!Validator::fileExists(input))
        Validator::badFile("File " + input + " cannot exists!");*/

        /*   string line;                                                     ///////////////
           ifstream fis(input);

           if (!fis)
               Validator::badFile("File " + input + " cannot opened!");

           while (getline(fis, line))
               output.push_back(line);

           fis.close();
       }*/