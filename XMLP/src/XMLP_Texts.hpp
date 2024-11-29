#define PROMT std::cout << "XMLP> ";
#define NO_FILE "XMLP> XML file is not loaded. Try load a valid XMl language file first"
#define TRY_FILE "XMLP> Trying to open file: "
#define TRY_REM_ID "XMLP> Trying to remove ID: "
#define ID_NOT_INT "XMLP> the input parameter is not an integer. Not ID should be and Integer."
#define FILE_LOADED "XMLP> XML file loaded"
#define FILE_LOAD_ERROR "XMLP> XML failed to load. Reason: "
#define REM_ID_WRONG_ID "XMLP> Notification ID not valid. Has to be an integer number greater than 0. Command '-r ' is ignored"
#define REM_ID_NOT_EXIST "ID does not exist in loaded XML-file. File not changed."
#define FILE_NOT_EXIST "XMLP> File does not exist. Try loading an XML language file using command: -o <path/filename"
#define TEXT_MISSING "Missing Notification/Menu_item text. Add text using command: -a for menu_item or -n for nottfication followed by <\"textstring\">"
#define TEXT_QUOTATION "Please input text with quotation marks. Example: \"TEXT\""
#define NOT_NEW_ID_CONFIRM  "Do you want to add Notification with new ID: "
#define NOT_NEW_TXT_CONFIRM     " and text :"
#define YES_NO "y [yes]   n [no]"
#define COMMANDS_DONE "Commands executed.Insert new commands or write \"exit\" to end"
#define NOT_NEW_ID_INSTR "To add new Notification text with new ID please use command: -n \"TEXT\" "
#define TEXT_NEW_ID_INSTR "To add new Menu text with new ID please use command: -m \"TEXT\" "