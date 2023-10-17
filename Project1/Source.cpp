#include<filesystem>
#include<fstream>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
	filesystem::path my_path = filesystem::current_path();

	my_path = filesystem::path("d:\\");
	cout << my_path.string();
	filesystem::path my_new_dir = my_path.append("MyCustomDirectory");
	if (!filesystem::exists(my_new_dir))
	{
		if (filesystem::create_directories(my_new_dir))
		{
			cout << "All create correctly!\n";
		}
		else
			cout << "Something wrong!\n";
	}
	else
		cout << "Directory is exists!\n";
	vector<string> my_files;
	for (filesystem::directory_iterator next(my_new_dir), end; next != end; ++next)
	{
		my_files.push_back(next->path().string());
		cout << next->path().string() <<endl;

	}
	try
	{
	
	}
	catch(exception ex)
	{
		cout << ex.what()<< endl;
	}
	for (vector<string>::iterator it = my_files.begin(); it!=my_files.end();++it)
	{
		cout << *it<<endl;
	}
	map<string, string> my_map;
	my_map["cat"] = "koshka";
	my_map["dog"] = "sobaka";
	for (map<string, string>::iterator it = my_map.begin(); it != my_map.end(); ++it)
	{
		cout << (*it).first <<" - "<<(*it).second<<endl;
	}
	string a = "Dog";
	map<string, string>::iterator it = my_map.find(a);
	if (it != my_map.end())
	{
		cout <<a <<" found!";
	}
	else
	{
		cout << a <<" not found!";
	}

	return 0;
}