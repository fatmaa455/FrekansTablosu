int main()
{
    int n;
    cout << "kac deger gireceksiniz: ";
    cin >> n;
    
    float dizi[n];
    
    for(int i=0;i<n;i++)
    {
        cout << i+1 << " . eleman: ";
        cin >> dizi[i];
    }
    
    float min=dizi[0];
    float max=dizi[0];
    for(int i=0;i<n;i++)
    {
        if(dizi[i] < min)
        {
            min=dizi[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(dizi[i] > max)
        {
            max=dizi[i];
        }
    }
    
    float R=max-min;
    float k=1;
    
    while(k <= sqrt(n))
    {
        k++;
    }
    int boyut=k;
    
    float h=R/k;
    h=ceil(h);
    
    float sinifLA[boyut];
    float sinifLU[boyut];
    float sinifSA[boyut];
    float sinifSU[boyut];
    float sinifF[boyut];
    float SON[boyut];
    float eklenikF[boyut];
    float oransalF[boyut];
    float oransalEF[boyut];
    
    
    // Sınıf alt limitleri
    for(int i=0;i<boyut;i++)
    {
        sinifLA[i]=min;
        min=min+h;
    }
    // Sınıf üst limitleri
    float temp;
    if(sinifLA[1] - (int)sinifLA[1] == 0)
    {
        temp=sinifLA[1]-1;
    }
    else
    {
        temp=sinifLA[1]-0.1;
    }
    for(int i=0;i<boyut;i++)
    {
        sinifLU[i]=temp;
        temp=temp+h;
    }
    // Sınıf üst sınırları
    float temp2=(sinifLA[1]+sinifLU[0])/2;
    for(int i=0;i<boyut;i++)
    {
        sinifSU[i]=temp2;
        temp2=temp2+h;
    }
    float temp3=sinifSU[0]-h;
    for(int i=0;i<boyut;i++)
    {
        sinifSA[i]=temp3;
        temp3=temp3+h;
    }
    
    // Sınıf frekansları
    float temp4;
    for(int i=0;i<k;i++)
    {
        temp4=0;
        for(int j=0;j<n;j++)
        {
            if(dizi[j]>=sinifSA[i] && dizi[j]<=sinifSU[i])
            {
                temp4++;
            }
        }
        sinifF[i]=temp4;
    }
    
    // SON
    for(int i=0;i<k;i++)
    {
        SON[i]=(sinifSA[i]+sinifSU[i])/2;
    }
    
    // Eklenik Frekans
    int temp5=sinifF[0];
    for(int i=0;i<k;i++)
    {
        eklenikF[i]=temp5;
        temp5=temp5+sinifF[i+1];
    }
    
    // Oransal Frekans
    for(int i=0;i<k;i++)
    {
        oransalF[i]=sinifF[i];
    }
    
    // Oransal Eklenik Frekans
    for(int i=0;i<k;i++)
    {
        oransalEF[i]=eklenikF[i];
    }
    
    cout << "Sinif Lim.   " << "Sinif Sin.   " << "Sinif F.   ";
    cout << "SON   " << "Eklenik F.   ";
    cout << "Oransal F.   " << "Oransal Eklenik F.   " << endl;
    
    cout << "Alt  " << "Ust     " << "Alt  " << "Ust" << endl;
    
    for(int i=0;i<k;i++)
    {
        cout << sinifLA[i] << "    ";
        cout << sinifLU[i] << "    ";
        cout << sinifSA[i] << "  ";
        cout << sinifSU[i] << "   ";
        cout << sinifF[i] << "        ";
        cout << SON[i] << "     ";
        cout << eklenikF[i] << "               ";
        cout << oransalF[i] << "/" << n << "               ";
        cout << oransalEF[i] << "/" << n;
        cout << endl;
    }
    
    cout << "\n\n\n\n\n";
}