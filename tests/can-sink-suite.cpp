#include <gtest/gtest.h>

#include <base/ICan.h>
#include <base/CanDataSink.h>

class TestCan : public ICan
{
public:
    void SendFrame(const Frame& frame) override
    {
        _last_frame = frame;
    }

    const ICan::Frame last_frame() const { return _last_frame; }
private:
    ICan::Frame _last_frame;
};

TEST(can_sink_suite, positive_nonnull)
{
    TestCan test_can_iface;

    CanDataSink sink(test_can_iface, 42);
    sink.write(42.666);

    ASSERT_EQ(test_can_iface.last_frame().id, 42);

    // -> 42666
    ASSERT_EQ(test_can_iface.last_frame().data[0], 0xAA);
    ASSERT_EQ(test_can_iface.last_frame().data[1], 0xA6);
    ASSERT_EQ(test_can_iface.last_frame().data[2], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[3], 0);

    ASSERT_EQ(test_can_iface.last_frame().data[4], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[5], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[6], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[7], 0);
}

TEST(can_sink_suite, negative)
{
    TestCan test_can_iface;

    CanDataSink sink(test_can_iface, 42);
    sink.write(-42.666);

    ASSERT_EQ(test_can_iface.last_frame().id, 42);

    // -> -42666 
    ASSERT_EQ(test_can_iface.last_frame().data[0], 0x56);
    ASSERT_EQ(test_can_iface.last_frame().data[1], 0x59);
    ASSERT_EQ(test_can_iface.last_frame().data[2], 0xFF);
    ASSERT_EQ(test_can_iface.last_frame().data[3], 0xFF);

    ASSERT_EQ(test_can_iface.last_frame().data[4], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[5], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[6], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[7], 0);
}

TEST(can_sink_suite, null)
{
    TestCan test_can_iface;

    CanDataSink sink(test_can_iface, 42);
    sink.write(0.0);

    ASSERT_EQ(test_can_iface.last_frame().id, 42);

    // -> 0
    ASSERT_EQ(test_can_iface.last_frame().data[0], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[1], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[2], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[3], 0);

    ASSERT_EQ(test_can_iface.last_frame().data[4], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[5], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[6], 0);
    ASSERT_EQ(test_can_iface.last_frame().data[7], 0);
}
