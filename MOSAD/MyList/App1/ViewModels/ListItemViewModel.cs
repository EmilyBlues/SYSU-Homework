﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.ObjectModel;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Imaging;
using Windows.Storage;

namespace MyList.ViewModels
{

    class TodoViewModels
    {
        private static TodoViewModels Instance;
        private TodoViewModels() { }
        public static TodoViewModels GetInstance()
        {
            if(Instance == null)
            {
                Instance = new TodoViewModels();
            }
            return Instance;
        }
        private ObservableCollection<Models.TodoItem> allItems = new ObservableCollection<Models.TodoItem>();

        public ObservableCollection<Models.TodoItem> AllItems { get { return this.allItems; } }

        private Models.TodoItem selectedItem = default(Models.TodoItem);

        public Models.TodoItem SelectedItem { get { return selectedItem; } set { this.selectedItem = value; } }

        public void AddTodoItem(String title, String description, DateTime date, ImageSource source, StorageFile f)
        {
            this.allItems.Add(new Models.TodoItem(title, description, date, source, f));
        }

        public void RemoveTodoItem(String id)
        {
            foreach (var item in this.allItems)
            {
                if (item.GetId() == id)
                {
                    this.allItems.Remove(item);
                    break;
                }
            }
            this.selectedItem = null;
        }

        public void UpdateTodoItem(String id, String title, String description, DateTime date, ImageSource source, StorageFile f)
        {
            foreach (var item in this.allItems)
            {
                if (item.GetId() == id)
                {
                    item.title = title;
                    item.description = description;
                    item.date = date;
                    item.source = source;
                    item.f = f;
                    break;
                }
            }
            this.selectedItem = null;
        }
    }
}
