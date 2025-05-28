#ifndef CommandInterface
#define CommandInterface

class ICommand {
 // Чисто виртуальная функция для выполнения команды.
 public:
  virtual void CommandExecute() = 0;
  // Виртуальный деструктор по умолчанию.
  virtual ~ICommand() = default;
};

#endif  // CommandInterface
