#pragma once

#include <gtest/gtest.h>
#include <filesystem>
#include <random>


struct tmpdir_fixture : public ::testing::Test
{
    void SetUp() override;
    void TearDown() override;

    std::filesystem::path dirname;
};
