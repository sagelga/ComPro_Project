void cashierInterface () {
    char username[137] = "Kumamon"; // Pull the username from the struct SESSION
    char text1[107] = "<store_name>";
    char text2[107] = "Welcome! My name is ";
    strcpy(text2,username);
    char text3[107] = "";
    char text4[107] = "";
    banner (text1,text2,text3,text4);
}