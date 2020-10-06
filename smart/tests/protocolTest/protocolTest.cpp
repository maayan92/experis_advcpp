#include "mu_test.h"

#include "protocol.hpp"
using namespace std;
using namespace smart_house;

BEGIN_TEST(test_protocol_pack)
    time_t currentTime = time(NULL);
    SensorInfo info("id", "42C|rising", localtime(&currentTime));
    string result;
    Protocol::Pack(result, info);

    ASSERT_EQUAL(34, (size_t)result[0]);

    size_t size = result[2];
    ASSERT_EQUAL(2, size);
    ASSERT_EQUAL("id", string(result, 3, result[2]));

    size = result[5];
    ASSERT_EQUAL(19, size);

    size = result[25];
    ASSERT_EQUAL(10, size);
    ASSERT_EQUAL("42C|rising", string(result, 26, result[25]));
END_TEST

BEGIN_TEST(test_protocol_un_pack)
    time_t currentTime = time(NULL);
    SensorInfo info("id", "42C|rising", localtime(&currentTime));
    string buffer;
    Protocol::Pack(buffer, info);

    SensorInfo resultInfo;
    Protocol::UnPack(buffer, resultInfo);

    ASSERT_EQUAL(resultInfo.m_deviceId, "id");
    ASSERT_EQUAL(resultInfo.m_data, "42C|rising");
END_TEST

BEGIN_SUITE(test_protocol)
    TEST(test_protocol_pack)
    TEST(test_protocol_un_pack)
END_SUITE