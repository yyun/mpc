#include <iostream>
#include "communicator/Writer.h"
using std::cout;
using std::endl;

int main()
{
    // msg.clientName=std::string(clientName);
    // msg.msgType=msgType;
    // msg.journalName=std::string(jname);
    // msg.idx=idx;
    // msg.response_status=response_status;

    // writetest|2|testj5|-1|-1   ->  reply:writetest|2|testj5|0|0
    // writetest|4|NULL|-1|-1   ->  reply:writetest|4|NULL|-1|1

    // testj8|2|testj8|-1|-1    -> reply:testj8|2|testj8|1|0

    std::string path = SYSTEM_JOURNAL_DIR + std::string("/");
    std::cout << path << std::endl;
    auto writer = Writer::create(path.c_str(), "testj8");
    if (writer == nullptr)
        return 0;
    for (int i = 0; i <= 100; ++i)
    {
        usleep(10000000);
        std::cout << i << std::endl;
        writer->WriteFrame(static_cast<void *>(&i), sizeof(int));
    }

    return 0;
}