
class Vector{
    int *arr;
    int cs;
    int ms;
public:
    Vector(int s=4){
        arr = new int[s];
        cs = 0;
        ms = s;
    }

    void push_back(const int d){
        if(cs==ms){
            ///Expand the vector if full
            int*oldArr = arr;
            int oldSize = ms;
            ms = ms<<1;
            arr = new int[ms];

            for(int i=0;i<cs;i++){
                arr[i] = oldArr[i];
            }
            delete [] oldArr;
            oldArr = NULL;
        }
        arr[cs] = d;
        cs++;
    }
    void pop_back(){
        if(cs>0){
            cs--;
        }
    }
    int size() const{
        return cs;
    }
    int capacity() const{
        return ms;
    }

    int operator[](int i){
        return arr[i];
    }
};
