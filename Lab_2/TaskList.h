make Worker				main class											+
make Validator			for wrong file way									+
make Reader, Writer															+
make Operations			operations											+
/*>
readfile <filename>  � ���������� ���������� ����� � ������, �������.���� � �����������, ����� � �����.

writefile <filename> � ������ ������ � ����.���� � �����, ����� � �����������.

grep <word> � ����� �� �������� ������ �����, ����������� ��������� �������� ������, ���������� �������� ����� <word>.���� � �����, ����� � �����.

sort � ������������������ ���������� �������� ������ �����.���� � �����, ����� � �����.

replace <word1> <word2> � ������ ����� <word1> ������ <word2> �� ������� ������.���� � �����, ����� � �����.

dump <filename> -��������� ��������� ����� � ��������� ����� � �������� ������.���� � �����, ����� � �����.
<*/
BlokProgram																	+

make Parser				main part, part where hapend magic					+

������ �������� �� ��������													+
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