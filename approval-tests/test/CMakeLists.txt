add_executable(approval-test main.cpp integration_tests-catch2.cpp integration_tests-approvals.cpp)
target_link_libraries(approval-test StoreLib Catch2::Catch2 ApprovalTests::ApprovalTests)