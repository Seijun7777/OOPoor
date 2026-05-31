#ifndef Menu_Admin_h
#define Menu_Admin_h
#include <fstream>
#include "Classes/Users.h"
#include "/Users/mrunknown/Documents/C++/Project_1/Project_1/assets/Arts.h"


void Menu_Admin(){
    // Opening DataBase
    std::fstream fs;
    fs.open("/Users/mrunknown/Documents/C++/Project_1/Project_1/DataBase/DataBase.bin", std::ios::in | std::ios::binary);
    
    // Array of users to work with them
    std::vector<User> users;
    
    User user;
    
    // filling the array
    while(fs.read((char*) &user, sizeof(User))){ users.push_back(user); }

    // closing the file
    fs.close();
    
    for(size_t i = 0; i<50; ++i) std::cout<<std::endl;
    ArtAdmin();
    
    
    while(true){
        std::cout<<std::endl<<std::endl<<"Name\t|\tPassword"<<std::endl
        <<"---------------------------"<<std::endl
        <<"        |"
        <<std::endl;
        for(size_t i = 1; i<users.size(); ++i){
            users[i].showDetails();
        }
        std::string data;
        
            std::cout << std::endl << "[*] Enter the account name to delete (or to exit '0'): ";
            std::cin >> data;
            
            if(data == "0") return;
            
            bool found = false;
            
            // 1. Сначала просто ищем и удаляем пользователя ИЗ ВЕКТОРА (из памяти)
            for(size_t i = 0; i < users.size(); ++i){
                if(users[i].getName() == data){
                    // Защита: не позволяем админу случайно удалить самого себя из списка
                    if(users[i].isAdmin_()) {
                        std::cout << "[!] You cannot delete the Admin account!" << std::endl;
                        found = true;
                        break;
                    }
                    
                    // Удаляем элемент из вектора
                    users.erase(users.begin() + i);
                    std::cout << "[+] Account '" << data << "' successfully removed from session memory." << std::endl;
                    found = true;
                    break; // Выходим из цикла поиска, так как имя уникальное
                }
            }
            
            if(!found) {
                std::cout << "[!] Account '" << data << "' not found." << std::endl;
                continue; // Если не нашли, файл не трогаем, просим ввод заново
            }
            
            // 2. Только если пользователь реально найден и удален из вектора,
            // ОДИН РАЗ перезаписываем файл базы данных чистым вектором
            try {
                fs.open("/Users/mrunknown/Documents/C++/Project_1/Project_1/DataBase/DataBase.bin", std::ios::out | std::ios::binary);
                
                for(size_t i = 0; i < users.size(); ++i) {
                    fs.write((char*) &users[i], sizeof(User));
                }
                
                fs.close();
                std::cout << "[───] Database file updated successfully." << std::endl;
                
            } catch(const std::fstream::failure &ex) {
                std::cout << "[!] File system error while saving updated data!" << std::endl;
                std::cout << ex.what() << std::endl << ex.code() << std::endl << std::endl;
                if(fs.is_open()) fs.close();
            }
        }
    
}

#endif /* Menu_Admin_h */
