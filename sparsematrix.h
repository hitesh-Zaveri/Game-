/*Please Read the comments below
For Null in the matrix type "NULL" in the value pitHoles keep the value int the matrix "-1" and
for gold keep the value of "Number of Coins" you want to place at that platform
And to see how to input give input see the "int main()" given below for example*/
#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
class List
{
    private:
        int index;
        int value;
        List *nextindex;
    public:
        List(int index)
        {
            this->index = index;
            nextindex = NULL;
            value = NULL;
        }
        List()
        {
            index = -1;
            value = NULL;
            nextindex = NULL;
        }
        void store(int index, int value)
        {
            List *current = this;
            List *previous = NULL;
            List *node = new List(index);
            node->value = value;
            while (current != NULL && current->index < index)
            {
                previous = current;
                current = current->nextindex;
            }
            if (current == NULL)
            {
                previous->nextindex = node;
            }
            else
            {
                if (current->index == index)
                {
                    //cout<<"DUPLICATE INDEX"<<endl;
                    return;
                }
                previous->nextindex = node;
                node->nextindex = current;
            }
            return;
        }

        int fetch(int index)
        {
            List *current = this;
            int value = NULL;
            while (current != NULL && current->index != index)
            {
                current = current->nextindex;
            }
            if (current != NULL)
            {
                value = current->value;
            }
            else
            {
                value = NULL;
            }
            return value;
        }

        int elementCount()
        {
            int elementCount = 0;
            List *current = this->nextindex;
            for ( ; (current != NULL); current = current->nextindex)
            {
                elementCount++;
            }
            return elementCount;
        }
};
class SparseArray
{
    private:
        List *start;
        int index;
    public:
        SparseArray(int index)
        {
            start = new List();
            this->index = index;
        }
        void store(int index, int value)
        {
            if (index >= 0 && index < this->index)
            {
                if (value != NULL)
                    start->store(index, value);
            }
            else
            {
                //cout<<"INDEX OUT OF BOUNDS"<<endl;
            }
        }
        int fetch(int index)
        {
            if (index >= 0 && index < this->index)
                return start->fetch(index);
            else
            {
                //cout<<"INDEX OUT OF BOUNDS"<<endl;
                return NULL;
            }
        }
        int elementCount()
        {
            return start->elementCount();
        }
};
class SparseMatrix
{
    private:
        int N;
        SparseArray **sparsearray;
    public:
    	SparseMatrix(){

		}
        SparseMatrix(int N)
        {
            this->N = N;
            sparsearray = new SparseArray* [N];
            for (int index = 0; index < N; index++)
            {
                sparsearray[index] = new SparseArray(N);
            }
        }
        //To Store the Sparse Matrix
        void store(int rowindex, int colindex, int value)
        {
            if (rowindex < 0 || rowindex > N)
            {
                //cout<<"row index out of bounds"<<endl;
                return;
            }
            if (colindex < 0 || colindex > N)
            {
                //cout<<"col index out of bounds"<<endl;
                return;
            }
            sparsearray[rowindex]->store(colindex, value);
        }
 		//To get the sparse matrix
        int get(int rowindex, int colindex)
        {
            if (rowindex < 0 || colindex > N)
            {
                //cout<<"row index out of bounds"<<endl;
                return 0;
            }
            if (rowindex < 0 || colindex > N)
            {
                //cout<<"col index out of bounds"<<endl;
                return 0;
            }
            return (sparsearray[rowindex]->fetch(colindex));
        }
        //It counts the number of elements in the Sparse matrix
        int elementCount()
        {
            int count = 0;
            for (int index = 0; index < N; index++)
            {
                count += sparsearray[index]->elementCount();
            }
            return count;
        }
};
#endif
