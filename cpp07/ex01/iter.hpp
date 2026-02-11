# ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename F>
void    iter(T* arrayAddr, int arrayLenght, F function) {
    if (!arrayAddr || !function)
        return ;
    for (int i = 0; i < arrayLenght; i++) {
        function(arrayAddr[i]);
    }
    return ;
}
# endif