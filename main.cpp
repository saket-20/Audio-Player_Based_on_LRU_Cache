#include <QCoreApplication>
#include<iostream>
#include<QtMultimedia/QMediaPlayer>
#include<QtMultimedia/QMediaPlaylist>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct node
{
    struct node *previous;
    node* next;
    int pgno;
};


class Hash
{
    int size1;
    node** arr;
public:
    Hash(int cap)
    {
        int i;

        size1=cap;
        arr=new node*[size1];

        for(i=0;i<size1;i++)
        {
            arr[i]=NULL;
        }

    }


    void modify_hash(int pos,node* val=NULL)//default argument if no value is given
    {
        arr[pos]=val;
    }



    node* return_node(int p)
    {
        return arr[p];
    }
};



Hash *hash1;//hash to be used throughout for the storing address of queue nodes

int count1=0;
int maxframes;
node *start=NULL, *end1=NULL;



bool is_queue_full()
{
    if(count1==maxframes)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


bool is_q_empty()
{
    if(start==end1&&end1==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void deQueue()
{
    if (is_q_empty())
    {
        return;
    }

    if(count1==1)
    {
        start = NULL;
        end1=NULL;
    }
else{
    node* N=end1;
    end1->previous->next=NULL;
    end1=end1->previous;

    delete N;}

}

void unlink_from_queue(node *n)
{
    (n->previous)->next=n->next;
}

void change_rear_to_previous(node*n)
{
    end1=n->previous;
    end1->next=NULL;


}
void put_node_at_start(node*n)
{
     n->previous=NULL;
     n->next=NULL;
    n->next=start;

        start->previous=n;
        start=n;
}
void access_page(int p)
{

    if (hash1->return_node(p)!=start&&hash1->return_node(p)!=NULL)
    {

        if (hash1->return_node(p)==end1)
        {
            unlink_from_queue(hash1->return_node(p));
            change_rear_to_previous(hash1->return_node(p));
        }
        if (hash1->return_node(p)->next!=NULL)
        {
            unlink_from_queue(hash1->return_node(p));
            hash1->return_node(p)->next->previous=hash1->return_node(p)->previous;
        }


  put_node_at_start(hash1->return_node(p));
    }
    //

    else if (hash1->return_node(p)==NULL)
    {
         if (is_queue_full()==1)
    {
        deQueue();
        count1-=1;
        hash1->modify_hash(end1->pgno);
    }

    node* N=new node;
    N->pgno=p;

    N->previous=NULL;
    N->next=NULL;

    N->next=start;
    if (is_q_empty()==1)
       {
           end1=N;
        }
    else
    {
        start->previous=N;
    }
    start=N;

    hash1->modify_hash(p,N);
    count1++;

    }


}
int main(int argc, char *argv[])
{
    maxframes=4;
    hash1=new Hash(10);
    int pg_acc;
    char cont='Y';
    cout<<"10 Songs available\n";
    cout<<"1.Tum Ho\n";
    cout<<"2.Kun Fayakun\n";
    cout<<"3.Phir se Ud Chala\n";
    cout<<"4.Jo Bhi Main\n";
    cout<<"5.Nadaan Parindey\n";
    cout<<"6.Saadda Haq\n";
    cout<<"7.Katiya Karun\n";
    cout<<"8.Aur Ho\n";
    cout<<"9.Tango For Taj\n";
    cout<<"10.The Dichotomy of Fame\n";
       for(;;)
       {
           cout<<"Enter the Song To be Accessed\n";
           cin>>pg_acc;
           access_page(pg_acc);
           cout<<"Enter Y to continue,Press any other key to Stop\n";
           cin>>cont;
           if(cont!='Y') break;
       }

    //4 video/audios  can be stored
    cout<<start->pgno<<" ";
     cout<<start->next->pgno<<" ";
      cout<<start->next->next->pgno<<" ";
       cout<<start->next->next->next->pgno<<" "<<endl;
    cout<<"Playlist Has Been created using your entries based on LRU cache\n";
    cout<<"3.Phir se Ud Chala\n";
     cout<<"4.Jo Bhi Main\n";
    cout<<"1.Tum Ho\n";
    cout<<"2.Kun Fayakun\n";


    QMediaPlayer *player;
    QMediaPlaylist *playlist1;
    QCoreApplication a(argc, argv);
    player = new QMediaPlayer;
    playlist1 = new QMediaPlaylist(player);
    node *ptr=start;
        int i=4;
        while(i>0)
        {
            if(ptr->pgno==1)
            {
                playlist1->addMedia(QUrl::fromLocalFile("/Users/saket/Downloads/Rockstar/Tum Ho Rockstar Full Song Ranbir Kapoor Nargis Fakhri.mp3"));
            }
            else if(ptr->pgno==2)
            {
                playlist1->addMedia(QUrl::fromLocalFile("/Users/saket/Downloads/Rockstar/Kun Faya Kun Full Video Song Rockstar Ranbir Kapoor A.R. Rahman, Javed Ali, Mohit Chauhan.mp3"));
            }
            else if(ptr->pgno==3)
            {
                playlist1->addMedia(QUrl::fromLocalFile("/Users/saket/Downloads/Rockstar/Phir Se Ud Chala Full Song Rockstar Ranbir Kapoor.mp3"));
            }
            else if(ptr->pgno==4)
            {
                playlist1->addMedia(QUrl::fromLocalFile("/Users/saket/Downloads/Rockstar/Jo bhi main Lyrical Video Rockstar Ranbir Kapoor A R Rahman.mp3"));
            }
            else if(ptr->pgno==5)
            {
                playlist1->addMedia(QUrl("/Users/saket/Downloads/Rockstar/NADAAN PARINDE (Full Song)RockstarRanbir KapoorA.R RahmanMohit Chauhan.mp3"));
            }
            else if(ptr->pgno==6)
            {
                playlist1->addMedia(QUrl("/Users/saket/Downloads/Rockstar/Sadda Haq Full Video Song RockstarRanbir Kapoor.mp3"));
            }
            else if(ptr->pgno==7)
            {
                playlist1->addMedia(QUrl("/Users/saket/Downloads/Rockstar/Katiya Karoon Lyrical Video Rockstar Ranbir Kapoor Nargis Fakhri A R Rahman.mp3"));
            }
            else if(ptr->pgno==8)
            {
                playlist1->addMedia(QUrl("/Users/saket/Downloads/Rockstar/Aur Ho Full Song Rockstar Ranbir Kapoor Nargis Fakhri.mp3"));
            }
            else if(ptr->pgno==9)
            {
               playlist1->addMedia(QUrl("/Users/saket/Downloads/Rockstar/Tango For Taj (1).mp3"));
            }
            else if(ptr->pgno==10)
            {
                playlist1->addMedia(QUrl("/Users/saket/Downloads/Rockstar/The Dichotomy of Fame Instrumental Song Rockstar Ranbir Kapoor, Nargis Fakhri.mp3"));
            }

            ptr=ptr->next;

            i--;
        }

    playlist1->setCurrentIndex(1);

    player->setPlaylist(playlist1);

    player->setVolume(50);

    player->play();
    cout<<"\nCache Size is set to 4 Currently\n";
    cout<<"\nCurrently Playing Audio!!!"<<endl;


    return a.exec();

}
