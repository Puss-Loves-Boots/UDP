#include<iostream>
#include<map>
#include<bitset>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{

    map<int, int> channel_map{ {1, 2}, {2, 19}, {3, 6}, {4, 23}, {5, 10}, {6, 28}, {7, 15}, {8, 32} };

#if 0
    vector<map<int, int>> final_map_vec;
    for (auto it : channel_map)
    {
        map<int, int> final_map{ {1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1}, {7,1}, {8,1},
                                {9,1}, {10,1}, {11,1}, {13,1}, {14,1}, {15,1}, {16,1}, {17,1},
                                {18,1}, {19,1}, {20,1}, {21,1}, {22,1}, {23,1}, {24,1}, {26,1},
                                {27,1}, {28,1}, {29,1}, {30,1}, {31,1}, {32,1}, {34,1}, {35,1} };
        final_map[it.second] = 0;
        final_map_vec.push_back(final_map);
    }

    for (auto it : final_map_vec)
    {
        for (auto it2 : it)
        {
            cout << it2.second << " ";
        }
        cout << endl;
    }

#endif

#if 1
    vector<map<string, map<int, int>>> final_map_vec;
    vector<vector<map<string, map<int, int>>>> final_map_vec_2;
    for (auto& channel : channel_map)
    {
        map<int, int> final_map_1{ {1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1}, {7,1}, {8,1},
                                {9,1}, {10,1}, {11,1}, {13,1}, {14,1}, {15,1}, {16,1}, {17,1},
                                {18,1}, {19,1}, {20,1}, {21,1}, {22,1}, {23,1}, {24,1}, {26,1},
                                {27,1}, {28,1}, {29,1}, {30,1}, {31,1}, {32,1}, {34,1}, {35,1} };

        if(final_map_1.find(channel.second - 1) == final_map_1.end())
            final_map_1[channel.second - 2] = 0;
        else
            final_map_1[channel.second - 1] = 0;
        final_map_vec.push_back({ {"3Q1Z", final_map_1} });

        map<int, int> final_map_2{ {1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1}, {7,1}, {8,1},
                                {9,1}, {10,1}, {11,1}, {13,1}, {14,1}, {15,1}, {16,1}, {17,1},
                                {18,1}, {19,1}, {20,1}, {21,1}, {22,1}, {23,1}, {24,1}, {26,1},
                                {27,1}, {28,1}, {29,1}, {30,1}, {31,1}, {32,1}, {34,1}, {35,1} };

        final_map_2[channel.second] = 0;
        final_map_vec.push_back({ {"3Q2Z", final_map_2} });

        map<int, int> final_map_3{ {1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1}, {7,1}, {8,1},
                                {9,1}, {10,1}, {11,1}, {13,1}, {14,1}, {15,1}, {16,1}, {17,1},
                                {18,1}, {19,1}, {20,1}, {21,1}, {22,1}, {23,1}, {24,1}, {26,1},
                                {27,1}, {28,1}, {29,1}, {30,1}, {31,1}, {32,1}, {34,1}, {35,1} };
        if (final_map_3.find(channel.second + 1) == final_map_3.end())
            final_map_3[channel.second + 2] = 0;
        else
            final_map_3[channel.second + 1] = 0;
        final_map_vec.push_back({ {"3Q3Z", final_map_3} });

        map<int, int> final_map_4{ {1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1}, {7,1}, {8,1},
                                {9,1}, {10,1}, {11,1}, {13,1}, {14,1}, {15,1}, {16,1}, {17,1},
                                {18,1}, {19,1}, {20,1}, {21,1}, {22,1}, {23,1}, {24,1}, {26,1},
                                {27,1}, {28,1}, {29,1}, {30,1}, {31,1}, {32,1}, {34,1}, {35,1} };
        if (final_map_4.find(channel.second + 2) == final_map_4.end())
            final_map_4[channel.second + 3] = 0;
        else
            final_map_4[channel.second + 2] = 0;
        final_map_vec.push_back({ {"3Q4Z", final_map_4} });

        final_map_vec_2.push_back(final_map_vec);
        final_map_vec.clear();
    }

    int channel_num = 0;
    for (auto& it : final_map_vec_2)
    {
        if (!it.empty())
        {
            channel_num++;
            cout << "--------------通道" << channel_num << "----------------" << endl;
            for (auto& it2 : it)
            {
                for (auto& it3 : it2)
                {
                    cout << it3.first << " ";
                    for (auto& it4 : it3.second)
                    {
                        cout << it4.second;
                    }
                    // cout << endl;
                }
                cout << endl;
            }
            // cout << endl;
        }
    }

#endif

}
