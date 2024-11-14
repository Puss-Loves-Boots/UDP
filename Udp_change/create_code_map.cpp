#include "create_code_map.h"

map<string, string> create_code_map_1(vector<string>& channel) 
{
    map<string, string> code_map;
    code_map["0X3FF"] = "11111111110";
    code_map["0X5FF"] = "11111111101";
    code_map["0X6FF"] = "11111111011";
    code_map["0X77F"] = "11111110111";
    code_map["0X7BF"] = "11111101111";
    code_map["0X7DF"] = "11111011111";
    code_map["0X7EF"] = "11110111111";
    code_map["0X7F7"] = "11101111111";
    code_map["0X7FB"] = "11011111111";
    code_map["0X7FD"] = "10111111111";
    code_map["0X7FE"] = "01111111111";
    code_map["0X7FF"] = "11111111111";

    channel.push_back("channel 13");
    channel.push_back("channel 14");
    channel.push_back("channel 15");
    channel.push_back("channel 16");
    channel.push_back("channel 17");
    channel.push_back("channel 18");
    channel.push_back("channel 19");
    channel.push_back("channel 20");
    channel.push_back("channel 21");
    channel.push_back("channel 22");
    channel.push_back("channel 23");
    
    return code_map;
}

map<string, string> create_code_map_2(vector<string>& channel) 
{
    map<string, string> code_map;
    code_map["0X1FF"] = "1111111110";
    code_map["0X2FF"] = "1111111101";
    code_map["0X37F"] = "1111111011";
    code_map["0X3BF"] = "1111110111";
    code_map["0X3DF"] = "1111101111";
    code_map["0X3EF"] = "1111011111";
    code_map["0X3F7"] = "1110111111";
    code_map["0X3FB"] = "1101111111";
    code_map["0X3FD"] = "1011111111";
    code_map["0X3FE"] = "0111111111";
    code_map["0X3FF"] = "1111111111";

    channel.push_back("channel 1");
    channel.push_back("channel 2");
    channel.push_back("channel 3");
    channel.push_back("channel 4");
    channel.push_back("channel 5");
    channel.push_back("channel 6");
    channel.push_back("channel 7");
    channel.push_back("channel 8");
    channel.push_back("channel 9");
    channel.push_back("channel 10");

    return code_map;
}

map<string, string> create_code_map_3(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["01111111"] = "01111111";
    code_map["10111111"] = "10111111";
    code_map["11011111"] = "11011111";
    code_map["11101111"] = "11101111";
    code_map["11110111"] = "11110111";
    code_map["11111011"] = "11111011";
    code_map["11111101"] = "11111101";
    code_map["11111110"] = "11111110";

    channel.push_back("channel 34");
    channel.push_back("channel 35");
    channel.push_back("channel 36");
    channel.push_back("channel 37");
    channel.push_back("channel 38");
    channel.push_back("channel 39");
    channel.push_back("channel 40");
    channel.push_back("channel 41");

    return code_map;
}

map<string, string> create_code_map_4(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["0X1FF"] = "1111111110";
    code_map["0X2FF"] = "1111111101";
    code_map["0X37F"] = "1111111011";
    code_map["0X3BF"] = "1111110111";
    code_map["0X3DF"] = "1111101111";
    code_map["0X3EF"] = "1111011111";
    code_map["0X3F7"] = "1110111111";
    code_map["0X3FB"] = "1101111111";
    code_map["0X3FD"] = "1011111111";
    code_map["0X3FE"] = "0111111111";
    code_map["0X3FF"] = "1111111111";

    channel.push_back("channel 29");
    channel.push_back("channel 30");
    channel.push_back("channel 31");
    channel.push_back("channel 32");
    channel.push_back("channel 34");
    channel.push_back("channel 35");
    channel.push_back("channel 36");
    channel.push_back("channel 37");
    channel.push_back("channel 38");
    channel.push_back("channel 39");

    return code_map;
}

map<string, string> create_code_map_5(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["0X7FFFFF"] = "111111111110111111111111";
    code_map["0XBFFFFF"] = "111111111101111111111111";
    code_map["0XDFFFFF"] = "111111111011111111111111";
    code_map["0XEFFFFF"] = "111111110111111111111111";
    code_map["0XF7FFFF"] = "111111101111111111111111";
    code_map["0XFBFFFF"] = "111111011111111111111111";
    code_map["0XFDFFFF"] = "111110111111111111111111";
    code_map["0XFEFFFF"] = "111101111111111111111111";
    code_map["0XFF7FFF"] = "111011111111111111111111";
    code_map["0XFFBFFF"] = "110111111111111111111111";
    code_map["0XFFDFFF"] = "101111111111111111111111";
    code_map["0XFFEFFF"] = "011111111111111111111111";
    code_map["0XFFF7FF"] = "111111111111111111111110";
    code_map["0XFFFBFF"] = "111111111111111111111101";
    code_map["0XFFFDFF"] = "111111111111111111111011";
    code_map["0XFFFEFF"] = "111111111111111111110111";
    code_map["0XFFFF7F"] = "111111111111111111101111";
    code_map["0XFFFFBF"] = "111111111111111111011111";
    code_map["0XFFFFDF"] = "111111111111111110111111";
    code_map["0XFFFFEF"] = "111111111111111101111111";
    code_map["0XFFFFF7"] = "111111111111111011111111";
    code_map["0XFFFFFB"] = "111111111111110111111111";
    code_map["0XFFFFFD"] = "111111111111101111111111";
    code_map["0XFFFFFE"] = "111111111111011111111111";
    code_map["0XFFFFFF"] = "111111111111111111111111";

    channel.push_back("channel 1");
    channel.push_back("channel 2");
    channel.push_back("channel 3");
    channel.push_back("channel 4");
    channel.push_back("channel 5");
    channel.push_back("channel 6");
    channel.push_back("channel 7");
    channel.push_back("channel 8");
    channel.push_back("channel 9");
    channel.push_back("channel 10");
    channel.push_back("channel 11");
    channel.push_back("channel 13");
    channel.push_back("channel 14");
    channel.push_back("channel 15");
    channel.push_back("channel 16");
    channel.push_back("channel 17");
    channel.push_back("channel 18");
    channel.push_back("channel 19");
    channel.push_back("channel 20");
    channel.push_back("channel 21");
    channel.push_back("channel 22");
    channel.push_back("channel 23");
    channel.push_back("channel 24");
    channel.push_back("channel 26");

    return code_map;
}

map<string, string> create_code_map_6(vector<string>& channel)
{
    map<string, string> code_map;
    	
    code_map["01111111"] = "01111111";
    code_map["10111111"] = "10111111";
    code_map["11011111"] = "11011111";
    code_map["11101111"] = "11101111";
    code_map["11110111"] = "11110111";
    code_map["11111011"] = "11111011";
    code_map["11111101"] = "11111101";
    code_map["11111110"] = "11111110";
    code_map["11111111"] = "11111111";

    channel.push_back("channel 40");
    channel.push_back("channel 41");
    channel.push_back("channel 45");
    channel.push_back("channel 46");
    channel.push_back("channel 47");
    channel.push_back("channel 48");
    channel.push_back("channel 49");
    channel.push_back("channel 50");

    return code_map;
}

map<string, string> create_code_map_7(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["1110111111101110"] = "0111111111101111";
    code_map["1110111111101101"] = "0111111111011111";
    code_map["1110111111101011"] = "0111111110111111";
    code_map["1110111111100111"] = "0111111101111111";
    code_map["1110111111011110"] = "1011111111101111";
    code_map["1110111111011101"] = "1011111111011111";
    code_map["1110111111011011"] = "1011111110111111";
    code_map["1110111111010111"] = "1011111101111111";
    code_map["1110111110111110"] = "1101111111101111";
    code_map["1110111110111101"] = "1101111111011111";
    code_map["1110111110111011"] = "1101111110111111";
    code_map["1110111110110111"] = "1101111101111111";
    code_map["1110111101111110"] = "1110111111101111";
    code_map["1110111101111101"] = "1110111111011111";
    code_map["1110111101111011"] = "1110111110111111";
    code_map["1110111101110111"] = "1110111101111111";

    channel.push_back("channel 1");
    channel.push_back("channel 2");
    channel.push_back("channel 3");
    channel.push_back("channel 4");
    channel.push_back("channel 5");
    channel.push_back("channel 6");
    channel.push_back("channel 7");
    channel.push_back("channel 8");
    channel.push_back("channel 9");
    channel.push_back("channel 10");
    channel.push_back("channel 11");
    channel.push_back("channel 13");
    channel.push_back("channel 14");
    channel.push_back("channel 15");
    channel.push_back("channel 16");
    channel.push_back("channel 17");

    return code_map;
}

map<string, string> create_code_map_8(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["1110111111101110"] = "0111111111101111";
    code_map["1110111111101101"] = "0111111111011111";
    code_map["1110111111101011"] = "0111111110111111";
    code_map["1110111111100111"] = "0111111101111111";
    code_map["1110111111011110"] = "1011111111101111";
    code_map["1110111111011101"] = "1011111111011111";
    code_map["1110111111011011"] = "1011111110111111";
    code_map["1110111111010111"] = "1011111101111111";
    code_map["1110111110111110"] = "1101111111101111";
    code_map["1110111110111101"] = "1101111111011111";
    code_map["1110111110111011"] = "1101111110111111";
    code_map["1110111110110111"] = "1101111101111111";
    code_map["1110111101111110"] = "1110111111101111";
    code_map["1110111101111101"] = "1110111111011111";
    code_map["1110111101111011"] = "1110111110111111";
    code_map["1110111101110111"] = "1110111101111111";

    channel.push_back("channel 1");
    channel.push_back("channel 2");
    channel.push_back("channel 3");
    channel.push_back("channel 4");
    channel.push_back("channel 5");
    channel.push_back("channel 6");
    channel.push_back("channel 7");
    channel.push_back("channel 8");
    channel.push_back("channel 9");
    channel.push_back("channel 10");
    channel.push_back("channel 11");
    channel.push_back("channel 13");
    channel.push_back("channel 14");
    channel.push_back("channel 15");
    channel.push_back("channel 16");
    channel.push_back("channel 17");

    return code_map;
}

map<string, string> create_code_map_9(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["1110111111101110"] = "1111011111111110";
    code_map["1110111111101101"] = "1111011111111101";
    code_map["1110111111101011"] = "1111011111111011";
    code_map["1110111111100111"] = "1111011111110111";
    code_map["1110111111011110"] = "1111101111111110";
    code_map["1110111111011101"] = "1111101111111101";
    code_map["1110111111011011"] = "1111101111111011";
    code_map["1110111111010111"] = "1111101111110111";
    code_map["1110111110111110"] = "1111110111111110";
    code_map["1110111110111101"] = "1111110111111101";
    code_map["1110111110111011"] = "1111110111111011";
    code_map["1110111110110111"] = "1111110111110111";
    code_map["1110111101111110"] = "1111111011111110";
    code_map["1110111101111101"] = "1111111011111101";
    code_map["1110111101111011"] = "1111111011111011";
    code_map["1110111101110111"] = "1111111011110111";

    channel.push_back("channel 1");
    channel.push_back("channel 2");
    channel.push_back("channel 3");
    channel.push_back("channel 4");
    channel.push_back("channel 5");
    channel.push_back("channel 6");
    channel.push_back("channel 7");
    channel.push_back("channel 8");
    channel.push_back("channel 9");
    channel.push_back("channel 10");
    channel.push_back("channel 11");
    channel.push_back("channel 13");
    channel.push_back("channel 14");
    channel.push_back("channel 15");
    channel.push_back("channel 16");
    channel.push_back("channel 17");

    return code_map;
}

map<string, string> create_code_map_10(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["1110111111101110"] = "1111011111111110";
    code_map["1110111111101101"] = "1111011111111101";
    code_map["1110111111101011"] = "1111011111111011";
    code_map["1110111111100111"] = "1111011111110111";
    code_map["1110111111011110"] = "1111101111111110";
    code_map["1110111111011101"] = "1111101111111101";
    code_map["1110111111011011"] = "1111101111111011";
    code_map["1110111111010111"] = "1111101111110111";
    code_map["1110111110111110"] = "1111110111111110";
    code_map["1110111110111101"] = "1111110111111101";
    code_map["1110111110111011"] = "1111110111111011";
    code_map["1110111110110111"] = "1111110111110111";
    code_map["1110111101111110"] = "1111111011111110";
    code_map["1110111101111101"] = "1111111011111101";
    code_map["1110111101111011"] = "1111111011111011";
    code_map["1110111101110111"] = "1111111011110111";

    channel.push_back("channel 1");
    channel.push_back("channel 2");
    channel.push_back("channel 3");
    channel.push_back("channel 4");
    channel.push_back("channel 5");
    channel.push_back("channel 6");
    channel.push_back("channel 7");
    channel.push_back("channel 8");
    channel.push_back("channel 9");
    channel.push_back("channel 10");
    channel.push_back("channel 11");
    channel.push_back("channel 13");
    channel.push_back("channel 14");
    channel.push_back("channel 15");
    channel.push_back("channel 16");
    channel.push_back("channel 17");

    return code_map;
}

map<string, string> create_code_map_11(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["channel1"] = "10111111111111111111111111111111";
    code_map["channel2"] = "11111111111111111011111111111111";
    code_map["channel3"] = "11111011111111111111111111111111";
    code_map["channel4"] = "11111111111111111111101111111111";
    code_map["channel5"] = "11111111101111111111111111111111";
    code_map["channel6"] = "11111111111111111111111110111111";
    code_map["channel7"] = "11111111111110111111111111111111";
    code_map["channel8"] = "11111111111111111111111111111011";

    channel.push_back("channel 1");
    channel.push_back("channel 2");
    channel.push_back("channel 3");
    channel.push_back("channel 4");
    channel.push_back("channel 5");
    channel.push_back("channel 6");
    channel.push_back("channel 7");
    channel.push_back("channel 8");
    channel.push_back("channel 9");
    channel.push_back("channel 10");
    channel.push_back("channel 11");
    channel.push_back("channel 13");
    channel.push_back("channel 14");
    channel.push_back("channel 15");
    channel.push_back("channel 16");
    channel.push_back("channel 17");
    channel.push_back("channel 18");
    channel.push_back("channel 19");
    channel.push_back("channel 20");
    channel.push_back("channel 21");
    channel.push_back("channel 22");
    channel.push_back("channel 23");
    channel.push_back("channel 24");
    channel.push_back("channel 26");
    channel.push_back("channel 27");
    channel.push_back("channel 28");
    channel.push_back("channel 29");
    channel.push_back("channel 30");
    channel.push_back("channel 31");
    channel.push_back("channel 32");
    channel.push_back("channel 34");
    channel.push_back("channel 35");

    return code_map;
}

map<string, string> create_code_map_12(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["channel1"] = "10111111111111111111111111111111";
    code_map["channel2"] = "11111111111111111011111111111111";
    code_map["channel3"] = "11111011111111111111111111111111";
    code_map["channel4"] = "11111111111111111111101111111111";
    code_map["channel5"] = "11111111101111111111111111111111";
    code_map["channel6"] = "11111111111111111111111110111111";
    code_map["channel7"] = "11111111111110111111111111111111";
    code_map["channel8"] = "11111111111111111111111111111011";

    channel.push_back("channel 1");
    channel.push_back("channel 2");
    channel.push_back("channel 3");
    channel.push_back("channel 4");
    channel.push_back("channel 5");
    channel.push_back("channel 6");
    channel.push_back("channel 7");
    channel.push_back("channel 8");
    channel.push_back("channel 9");
    channel.push_back("channel 10");
    channel.push_back("channel 11");
    channel.push_back("channel 13");
    channel.push_back("channel 14");
    channel.push_back("channel 15");
    channel.push_back("channel 16");
    channel.push_back("channel 17");
    channel.push_back("channel 18");
    channel.push_back("channel 19");
    channel.push_back("channel 20");
    channel.push_back("channel 21");
    channel.push_back("channel 22");
    channel.push_back("channel 23");
    channel.push_back("channel 24");
    channel.push_back("channel 26");
    channel.push_back("channel 27");
    channel.push_back("channel 28");
    channel.push_back("channel 29");
    channel.push_back("channel 30");
    channel.push_back("channel 31");
    channel.push_back("channel 32");
    channel.push_back("channel 34");
    channel.push_back("channel 35");

    return code_map;
}

map<string, string> create_code_map_13(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["channel1"] = "10111111111111111111111111111111";
    code_map["channel2"] = "11111111111111111011111111111111";
    code_map["channel3"] = "11111011111111111111111111111111";
    code_map["channel4"] = "11111111111111111111101111111111";
    code_map["channel5"] = "11111111101111111111111111111111";
    code_map["channel6"] = "11111111111111111111111110111111";
    code_map["channel7"] = "11111111111110111111111111111111";
    code_map["channel8"] = "11111111111111111111111111111011";

    channel.push_back("channel 1");
    channel.push_back("channel 2");
    channel.push_back("channel 3");
    channel.push_back("channel 4");
    channel.push_back("channel 5");
    channel.push_back("channel 6");
    channel.push_back("channel 7");
    channel.push_back("channel 8");
    channel.push_back("channel 9");
    channel.push_back("channel 10");
    channel.push_back("channel 11");
    channel.push_back("channel 13");
    channel.push_back("channel 14");
    channel.push_back("channel 15");
    channel.push_back("channel 16");
    channel.push_back("channel 17");
    channel.push_back("channel 18");
    channel.push_back("channel 19");
    channel.push_back("channel 20");
    channel.push_back("channel 21");
    channel.push_back("channel 22");
    channel.push_back("channel 23");
    channel.push_back("channel 24");
    channel.push_back("channel 26");
    channel.push_back("channel 27");
    channel.push_back("channel 28");
    channel.push_back("channel 29");
    channel.push_back("channel 30");
    channel.push_back("channel 31");
    channel.push_back("channel 32");
    channel.push_back("channel 34");
    channel.push_back("channel 35");

    return code_map;
}

map<string, string> create_code_map_14(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["channel1"] = "10111111111111111111111111111111";
    code_map["channel2"] = "11111111111111111011111111111111";
    code_map["channel3"] = "11111011111111111111111111111111";
    code_map["channel4"] = "11111111111111111111101111111111";
    code_map["channel5"] = "11111111101111111111111111111111";
    code_map["channel6"] = "11111111111111111111111110111111";
    code_map["channel7"] = "11111111111110111111111111111111";
    code_map["channel8"] = "11111111111111111111111111111011";

    channel.push_back("channel 1");
    channel.push_back("channel 2");
    channel.push_back("channel 3");
    channel.push_back("channel 4");
    channel.push_back("channel 5");
    channel.push_back("channel 6");
    channel.push_back("channel 7");
    channel.push_back("channel 8");
    channel.push_back("channel 9");
    channel.push_back("channel 10");
    channel.push_back("channel 11");
    channel.push_back("channel 13");
    channel.push_back("channel 14");
    channel.push_back("channel 15");
    channel.push_back("channel 16");
    channel.push_back("channel 17");
    channel.push_back("channel 18");
    channel.push_back("channel 19");
    channel.push_back("channel 20");
    channel.push_back("channel 21");
    channel.push_back("channel 22");
    channel.push_back("channel 23");
    channel.push_back("channel 24");
    channel.push_back("channel 26");
    channel.push_back("channel 27");
    channel.push_back("channel 28");
    channel.push_back("channel 29");
    channel.push_back("channel 30");
    channel.push_back("channel 31");
    channel.push_back("channel 32");
    channel.push_back("channel 34");
    channel.push_back("channel 35");

    return code_map;
}

map<string, string> create_code_map_15(vector<string>& channel)
{
    map<string, string> code_map;
    code_map["channel1,3Q1Z(1110)"] = "01111111111111111111111111111111";
    code_map["channel1,3Q2Z(1101)"] = "10111111111111111111111111111111";
    code_map["channel1,3Q3Z(1011)"] = "11011111111111111111111111111111";
    code_map["channel1,3Q4Z(0111)"] = "11101111111111111111111111111111";
    code_map["channel2,3Q1Z(1110)"] = "11111111111111110111111111111111";
    code_map["channel2,3Q2Z(1101)"] = "11111111111111111011111111111111";
    code_map["channel2,3Q3Z(1011)"] = "11111111111111111101111111111111";
    code_map["channel2,3Q4Z(0111)"] = "11111111111111111110111111111111";
    code_map["channel3,3Q1Z(1110)"] = "11110111111111111111111111111111";
    code_map["channel3,3Q2Z(1101)"] = "11111011111111111111111111111111";
    code_map["channel3,3Q3Z(1011)"] = "11111101111111111111111111111111";
    code_map["channel3,3Q4Z(0111)"] = "11111110111111111111111111111111";
    code_map["channel4,3Q1Z(1110)"] = "11111111111111111111011111111111";
    code_map["channel4,3Q2Z(1101)"] = "11111111111111111111101111111111";
    code_map["channel4,3Q3Z(1011)"] = "11111111111111111111110111111111";
    code_map["channel4,3Q4Z(0111)"] = "11111111111111111111111011111111";
    code_map["channel5,3Q1Z(1110)"] = "11111111011111111111111111111111";
    code_map["channel5,3Q2Z(1101)"] = "11111111101111111111111111111111";
    code_map["channel5,3Q3Z(1011)"] = "11111111110111111111111111111111";
    code_map["channel5,3Q4Z(0111)"] = "11111111111011111111111111111111";
    code_map["channel6,3Q1Z(1110)"] = "11111111111111111111111101111111";
    code_map["channel6,3Q2Z(1101)"] = "11111111111111111111111110111111";
    code_map["channel6,3Q3Z(1011)"] = "11111111111111111111111111011111";
    code_map["channel6,3Q4Z(0111)"] = "11111111111111111111111111101111";
    code_map["channel7,3Q1Z(1110)"] = "11111111111101111111111111111111";
    code_map["channel7,3Q2Z(1101)"] = "11111111111110111111111111111111";
    code_map["channel7,3Q3Z(1011)"] = "11111111111111011111111111111111";
    code_map["channel7,3Q4Z(0111)"] = "11111111111111101111111111111111";
    code_map["channel8,3Q1Z(1110)"] = "11111111111111111111111111110111";
    code_map["channel8,3Q2Z(1101)"] = "11111111111111111111111111111011";
    code_map["channel8,3Q3Z(1011)"] = "11111111111111111111111111111101";
    code_map["channel8,3Q4Z(0111)"] = "11111111111111111111111111111110";

    channel.push_back("channel 1");
    channel.push_back("channel 2");
    channel.push_back("channel 3");
    channel.push_back("channel 4");
    channel.push_back("channel 5");
    channel.push_back("channel 6");
    channel.push_back("channel 7");
    channel.push_back("channel 8");
    channel.push_back("channel 9");
    channel.push_back("channel 10");
    channel.push_back("channel 11");
    channel.push_back("channel 13");
    channel.push_back("channel 14");
    channel.push_back("channel 15");
    channel.push_back("channel 16");
    channel.push_back("channel 17");
    channel.push_back("channel 18");
    channel.push_back("channel 19");
    channel.push_back("channel 20");
    channel.push_back("channel 21");
    channel.push_back("channel 22");
    channel.push_back("channel 23");
    channel.push_back("channel 24");
    channel.push_back("channel 26");
    channel.push_back("channel 27");
    channel.push_back("channel 28");
    channel.push_back("channel 29");
    channel.push_back("channel 30");
    channel.push_back("channel 31");
    channel.push_back("channel 32");
    channel.push_back("channel 34");
    channel.push_back("channel 35");

    return code_map;
}
