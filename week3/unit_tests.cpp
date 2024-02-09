#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stacks.h"
#include "queues.h"

TEST_CASE("stacks") {
    SUBCASE("size check") {
        stack<node> s = get_empty_node_stack();
        CHECK_EQ(s.size(), 0);
    };

    SUBCASE("copy") {
        stack<node> s1 = get_empty_node_stack();
        stack<node> s2;
        node n;
        n.name = "test";
        n.number = 0;
        add_node_to_stack(s1, n);

        s2 = s1;
        CHECK(s1.size() == s2.size());
        CHECK(s1.top().name == s2.top().name);
        CHECK(s1.top().number == s2.top().number);
    }

    SUBCASE("add to stack") {
        stack<node> s1 = get_empty_node_stack();
        node n;
        n.name = "test";
        n.number = 0;
        add_node_to_stack(s1, n);

        CHECK(s1.size() == 1);
        CHECK(s1.top().name == "test");
        CHECK(s1.top().number == 0);
    }
    
    SUBCASE("pop empty stack") {
        stack<node> s1 = get_empty_node_stack();
        CHECK_THROWS(remove_top_node(s1));
    }
};

TEST_CASE("queues") {
    SUBCASE("size check") {
        queue<node> q = get_empty_node_queue();
        CHECK_EQ(q.size(), 0);
    }

    SUBCASE("copy") {
        queue<node> q1 = get_empty_node_queue();
        queue<node> q2;
        node n;
        n.name = "test";
        n.number = 0;
        enqueue_node(q1, n);

        q2 = q1;
        CHECK(q1.size() == q2.size());
        CHECK(q1.front().name == q2.front().name);
        CHECK(q1.front().number == q2.front().number);
    }

    SUBCASE("add to queue") {
        queue<node> q1 = get_empty_node_queue();
        node n;
        n.name = "test";
        n.number = 0;
        enqueue_node(q1, n);

        CHECK(q1.size() == 1);
        CHECK(q1.front().name == "test");
        CHECK(q1.front().number == 0);
    }

    SUBCASE("dequeue empty queue") {
        queue<node> q1 = get_empty_node_queue();
        CHECK_THROWS(dequeue_node(q1));
    }
};