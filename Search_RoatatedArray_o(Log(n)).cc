int search(int arr[], int l, int h, int key)
    {
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        //unrotate the array
            
        //assumin two elements present
        if (l > h) 
            return -1;
        int mid = (l + h) / 2;
        if (arr[mid] == key) return mid;
        
        if (arr[l] <= arr[mid]) 
        {
            if (arr[l] <= key && key <= arr[mid])
                return search(arr, l, mid - 1, key);
            
            return search(arr, mid + 1, h, key);
        }
        
        if (arr[mid] <= arr[h]) 
        {
            if (arr[mid] <= key && key <= arr[h]) 
                return search(arr, mid + 1, h, key);
            
            return search(arr, l, mid - 1, key);
        }
        
        return -1;
        //complete the function here
    }
