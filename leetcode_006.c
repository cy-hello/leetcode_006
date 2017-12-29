一  题目：
ZigZag Conversion("之"字型转换)

二  题目要求：
	输入一串字符串，但是系统会按照”之“字型排列（会提供行数），你要返回的”之“字型排列后的字符串
	
三	题目分析：
/*
** 列出之字形排列的字符串，找出行号和列号规律，按顺序放进数组中
**
*/

四	编写代码：

class Solution {
public:
    string convert(string s, int numRows) {

        /*防止字符串为空*/
        if (s.length() == 0)
        {
            return s;
        }
        /*字符串不应该被分成一行  ，如果一行是不能成为之字型*/
        if (numRows == 1)
        {
            return s;
        }
        /*初始化变量*/
        int str_pos  = 0;/*表示当前插入字符串的长度*/
        int str_pos2;/*str_pos2是表示在return的字符串中应该第几个插入*/
        string str_ret;
        /*依次取字符串,把空格、换行符全去掉*/
        for(int i = 0;i < numRows;++i)
        {
            for (int j = 0;j < s.length() / (2 * numRows -2) + 2;++j)/*有多少列是：s.length() / (2 * numRows -2)*/
            {
                str_pos  = 2 * (numRows - 1) * j + i;
                str_pos2 = str_pos - 2 * i;
                if (str_pos2 >= 0 && str_pos2 < s.length() && i != 0 && i != numRows - 1)
                {
                    str_ret.push_back(s[str_pos2]);/*push_back是向数组末尾插入字符*/
                }
                
                if (str_pos < s.length())/*如果字符串的位置还没到底，继续插入*/
                {  
                    str_ret.push_back(s[str_pos]);
                }
            }

        }
        
        return str_ret;
    }
};