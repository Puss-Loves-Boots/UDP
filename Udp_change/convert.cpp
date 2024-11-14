#include "convert.h"

//函数指针
using create_code_map_ptr = map<string, string>(*)(vector<string>&);

//函数指针容器，实现分别调用
vector<create_code_map_ptr> create_code_map_vector = {create_code_map_1, create_code_map_2, create_code_map_3, create_code_map_4,
                                                      create_code_map_5, create_code_map_6, create_code_map_7, create_code_map_8, 
                                                      create_code_map_9, create_code_map_10,create_code_map_11, create_code_map_12, 
                                                      create_code_map_13, create_code_map_14, create_code_map_15};

string code_convert(int map_index, string code)
{
    map_index--;
    if (static_cast<size_t>(map_index) < 0 || static_cast<size_t>(map_index) > create_code_map_vector.size())
    {
        return "Invalid map index";
    }
    else
    {
        vector<string> channel;
        map<string, string> code_map = create_code_map_vector[map_index](channel);
        return code_map[code];
    }
}
