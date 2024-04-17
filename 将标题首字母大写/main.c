char* capitalizeTitle(char* title) {
	char* result = (char*)malloc(strlen(title) + 1);
	if (result == NULL) {
		return NULL;
	}

	char* ptr = result; // 指向结果字符串的指针
	char* wordstart = title; // 指向当前单词开始的指针

	while (*title)
	{
		if (*title == ' ') { // 检测到空格，表示一个单词结束
			int len = title - wordstart; // 计算当前单词的长度  
			if (len <= 2) { //  如果单词长度小于等于 2
				for (int i = 0; i < len; i++)
				{
					*ptr++ = tolower(*(wordstart + i)); //将所有字母转为小写 
				}
			}
			else
			{
				*ptr++ = toupper(*wordstart); //将首字母转为大写
				for (int i = 1; i < len; i++)
				{
					*ptr++ = tolower(*(wordstart + i)); //将剩余字母转为小写 
				}
			}
			*ptr++ = ' '; // 添加空格到结果字符串中 
			wordstart = title + 1; // 更新 wordStart 到下一个单词的开始 

		}
		title++; //继续遍历字符串
	}
    
    // 处理最后一个单词（后面没有空格）  
	int len = strlen(wordstart);
	if (len <= 2)
	{
		for (int i = 0; i < len; i++)
		{
			*ptr++ = tolower(*(wordstart + i));
		}
	}
	else
	{
		*ptr++ = toupper(*wordstart);
		for (int i = 1; i < len; i++)
		{
			*ptr++ = tolower(*(wordstart + i));
		}
	}
	*ptr = '\0';

	return result;
}



int main() {  
    char title[] = "capiTalIze tHe titLe";  
    char* capitalizedTitle = capitalizeTitle(title);  
    if (capitalizedTitle != NULL) {  
        printf("%s\n", capitalizedTitle); // 输出结果  
        free(capitalizedTitle); // 释放动态分配的内存  
    }  
      
    return 0;  
}