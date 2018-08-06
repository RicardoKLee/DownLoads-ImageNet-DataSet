#pragma once
#ifndef  MAIN
#define MAIN
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <omp.h>
#include <io.h>
int main(int argc, char** argv)
{
	if(argc<5)
	{
		std::cout << "参数太少！" << std::endl;
	}
	//文件
	std::vector<std::string> files;
	char searchPath[200] = "";
	sprintf(searchPath, "%s", argv[2]);
	char infileName[] = "";
	sprintf(infileName, "%s\\ImageNetKeys.txt", searchPath);
	std::ifstream infile(infileName);
	if (!infile)
	{
		std::cout << "打开文件错误" << std::endl;
	}
	files.clear();
	while (!infile.eof())
	{
		char info[256]="";
		infile.getline(info, 256);
		std::string *str = new std::string(info);
		files.push_back(*str);
	}
	char exe[256] = "";
	sprintf(exe, "%s   --process-per-tab  --app", argv[1]);
	int i = 0;
	#pragma omp parallel num_threads(atoi(argv[3])) private(i) shared(files) 
	{
		#pragma omp for schedule(dynamic) //dynamic
		for (i = 0;i < files.size();i++)
		{
			char filesName[] = "";
			sprintf(filesName, "%s\\%s.tar", searchPath, files[i].c_str());
			intptr_t  info = 0;
			struct _finddata_t fileInfo;

			char url[] = "";
			info = _findfirst(filesName, &fileInfo);
			if (info == -1L)
			{
				sprintf(url, "%s http://www.image-net.org/download/synset?wnid=%s&username=%s&accesskey=%s&release=latest&src=stanford", exe, files[i].c_str(),argv[4],argv[5]);
				WinExec(url, 0);
			}
			else
			{
				_findclose(info);
				continue;
			}
			while (1)
			{
				info = _findfirst(filesName, &fileInfo);
				if (info != -1L)
				{
					std::cout << "find" << std::endl;
					_findclose(info);
					break;
				}
			}
		}
	}
	system("pause");
	return 0;
}
#endif // ! MAIN
