#ifdef __APPLE__
    #include <iostream>
    #include <vector>
    #include <map>
    #include <algorithm>
    using namespace std;
#elif
    #include <bits/stdc++.h>
#endif 


#define PRINT_CONTAINER_ELEMENTS(container) \
    do { \
        for (const auto& element : container) { \
            cout << element << " "; \
        } \
        cout << endl; \
    } while (0)


#define PRINT_2D_VECTOR_ELEMENTS(vector2D) \
    do { \
        int i = 0; \
        std::cout<< " |"; \
        int col_num = vector2D[0].size(); \
        for (int j = 0; j < col_num; j++) { \
            std::cout << j << " "; \
        } \
        i = 0; \
        std::cout << "\n----------------------------" << std::endl; \
        for (const auto& row : vector2D) { \
            std::cout << i++ << "|"; \
            PRINT_CONTAINER_ELEMENTS(row); \
        } \
        std::cout << "----------------------------" << std::endl; \
    } while(0)
