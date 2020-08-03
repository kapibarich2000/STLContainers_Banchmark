#include "iostream"
#include "Tests.h"


// FOR -> Test_AddElements()
void start_PushFront_Test();
void start_PushBack_Test();
void start_Insert_InTheMiddle();
void start_InsertInto_Associative_And_UnorderedAssociative_Containers();

// FOR -> Test_WithElement()
void start_FindElement_CalculateAmount();

// FOR -> Test_MergingContainers()
void start_Merging_Test();

// FOR -> Test_DeletingElements()
void start_PopFront_Test();
void start_PopBack_Test();
void start_Delete_FromTheMiddle();
void start_DeletingFrom_Associative_And_UnorderedAssociative_Containers();


// Tests for adding elements

void Test_AddElements(){

    std::cout<<std::endl;
    std::cout<<" /// Test_AddElements /// \n\n";

    start_PushFront_Test();

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

    start_PushBack_Test();

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

     start_Insert_InTheMiddle();

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

    start_InsertInto_Associative_And_UnorderedAssociative_Containers();

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

}


// Search and summation of the elements

void Test_WithElement(){

    std::cout<<std::endl;
    std::cout<<" /// Test_WithElement /// \n\n";

    start_FindElement_CalculateAmount();

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

}


//  Merging two identical containers into one

void Test_MergingContainers() {
    std::cout<<std::endl;
    std::cout<<" /// Test_MergingContainers /// \n\n";
    start_Merging_Test();
}


// Tests for deleting elements

void Test_DeleteElements(){
    std::cout<<std::endl;
    std::cout<<" /// Test_DeleteElements /// \n\n";

    start_PopFront_Test();

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

    start_PopBack_Test();

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

      start_Delete_FromTheMiddle();

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

    start_DeletingFrom_Associative_And_UnorderedAssociative_Containers();

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

}
