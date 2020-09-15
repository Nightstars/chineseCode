#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QString text="½ò";
	for (int i = 0; i < text.length(); i++)
	{
		QString str = text.at(i);
		QByteArray arr = str.toLocal8Bit();
		unsigned char high = 0;
		unsigned char low = 0;
		int code = 0;

		if (arr.size() == 1)
		{
			high = 0;
			low = arr.at(0) & 0xff;
		}
		else if (arr.size() == 2)
		{
			high = arr.at(0) & 0xff;
			low = arr.at(1) & 0xff;
		}

		if (high < 0xa1 || low < 0xa1)
		{
			continue;
		}
		else
		{
			code = (high - 0xa0) * 100 + low - 0xa0;
		}
		string code1 = code + " ";
		cout << code1<< endl;
		//pinyins += GetPinyin(code);
	}
	//cout << "aa" << endl;
	return a.exec();
}
