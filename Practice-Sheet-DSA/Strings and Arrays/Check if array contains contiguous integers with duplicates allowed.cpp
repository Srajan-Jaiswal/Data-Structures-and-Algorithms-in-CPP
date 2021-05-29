bool areElementsContiguous(int arr[], int n)
    {
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(arr[i]);
        }
        auto i = s.begin();
        auto j = s.begin();
        j++;
        while (j != s.end())
        {
            if (*j == *i + 1)
            {
                i++;
                j++;
            }
            else
            {
                return 0;
                break;
            }
        }
        return 1;
    }
