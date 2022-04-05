#ifdef  __WINDOWS__
#ifdef  __MAKE_DLL__
#define EXPORT __declspec (dllexport)
#else
#define EXPORT __declspec (dllimport)
#endif  // ! __MAKE_DLL__
#else
#define EXPORT
#endif  // ! __WINDOWS__