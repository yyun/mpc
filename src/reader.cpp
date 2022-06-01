#include <iostream>
#include "communicator/Reader.h"
using std::cout;
using std::endl;

int main()
{

    // testReader|1|NULL|-1|-1   ->reply:testReader|1|NULL|0|0
    // testReader|5|testj5|-1|-1  ->reply:testReader|5|testj5|-1|0
    // 先注册reader信息 添加journal

    auto reader = Reader::create("testReader");
    std::string path = SYSTEM_JOURNAL_DIR + std::string("/");
    reader->addJournal(path.c_str(), "testj5");
    // reader->addJournal(path.c_str(), "testj6");
    while (true)
    {
        auto frameptr = static_cast<FrameHeader *>(reader->readFrame());
        if (frameptr == nullptr)
            continue;
        else
        {
            long duration = getNanoTime() - frameptr->nano;
            std::cout << "time duration:" << duration << "," << frameptr->length << std::endl;
        }
    }

    return 0;
}