//
//  MainView.swift
//  MyNotes
//
//  Created by roger on 28/02/25.
//

import SwiftUI

struct MainView: View {
    @ObservedObject var myNotes: MyNotes
    @State var searchString = ""
    @State var newFolderName = ""
    @State var showingPopover = false
    var body: some View {
        ZStack {
            NavigationView {
                List {
                    TextField("Search", text: $searchString)
                    Section(
                        header:
                            Text("On My iPhone")
                            .font(.title3)
                            .fontWeight(.bold)
                            .foregroundColor(.black)
                    ) {
                        if myNotes.folders.count > 0 {
                            FolderCell(name: "All on my iPhone")
                        }
                        FolderCell(name: "Notes")
                        ForEach(myNotes.folders) { folder in
                            FolderCell(name: folder.name)
                        }
                        .onDelete(perform: { indexSet in
                            myNotes.folders.remove(atOffsets: indexSet)
                        })
                    }
                    .textCase(nil)
                }
                .listStyle(InsetGroupedListStyle())
                .navigationTitle("Folders")
                .toolbar {
                    ToolbarItemGroup(placement: .navigationBarTrailing) {
                        EditButton()
                    }
                    ToolbarItemGroup(placement: .bottomBar) {
                        Image(systemName: "folder.badge.plus")
                            .onTapGesture {
                                showingPopover.toggle()
                            }
                        Image(systemName: "square.and.pencil")
                    }
                }
            }
            if showingPopover {
                CreateNewFolder($showingPopover, with: myNotes)
            }
        }
    }
}
struct CreateNewFolder: View {
    @ObservedObject var myNotes: MyNotes
    @Binding var showingPopover: Bool
    @State var newFolderName = ""
    init(_ showingPopover: Binding<Bool>, with myNotes: MyNotes) {
        self._showingPopover = showingPopover
        self.myNotes = myNotes
    }
    var body: some View {
        GeometryReader { geo in
            ZStack {
                RoundedRectangle(cornerRadius: 7)
                    .fill(Color(.systemGray4))
                    .frame(
                        width: geo.size.width * 0.70,
                        height: geo.size.width * 0.40, alignment: .center)
                VStack {
                    Text("New Folder").font(.headline)
                    Text("Enter a name for this folder").font(.subheadline)
                    Spacer()
                    TextField("Name", text: $newFolderName)
                        .frame(width: 200, height: 10)
                        .padding()
                        .background(Color(.white))
                        .cornerRadius(7)
                    Spacer()
                    Color.gray.frame(width: 200, height: CGFloat(1))
                    HStack {
                        Button(action: {
                            showingPopover.toggle()
                        }) {
                            Text("Cancel").frame(maxWidth: .infinity)
                        }
                        Button(action: {
                            myNotes.folders.append(Folder(name: newFolderName))
                            showingPopover.toggle()
                        }) {
                            Text("Save").frame(maxWidth: .infinity)
                        }
                    }
                }
                .frame(
                    width: geo.size.width * 0.70, height: geo.size.width * 0.35)
            }
            .frame(
                width: geo.size.width, height: geo.size.height,
                alignment: .center)
        }
    }
}

struct FolderCell: View {
    var name: String
    var body: some View {
        HStack {
            Image(systemName: "folder")
            Text(name)
        }
    }
}

#Preview {
    let testNotes = MyNotes()
    testNotes.folders = testFolders
    return MainView(myNotes: testNotes)
}
