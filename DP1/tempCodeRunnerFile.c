 temp_x = arr[j+1][0];
                temp_y = arr[j+1][1];
                arr[j+1][0] = arr[j][0];
                arr[j+1][1] = arr[j][1];
                arr[j][0] = temp_x;
                arr[j][1] = temp_y;