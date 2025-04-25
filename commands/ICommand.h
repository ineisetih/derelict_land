#ifndef CommandInterface
#define CommandInterface

class ICommand {
 public:
  virtual void CommandExecute() = 0;
  virtual ~ICommand() = default;
};

#endif  // CommandInterface
