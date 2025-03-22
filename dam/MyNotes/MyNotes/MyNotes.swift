//
//  MyNotes.swift
//  MyNotes
//
//  Created by roger on 28/02/25.
//

import Foundation

class MyNotes: ObservableObject {
    @Published var folders = [Folder]()
}

struct Folder: Identifiable {
    var id = UUID()

    var name: String
}

var testFolders = [
    Folder(name: "Folder"),
    Folder(name: "Folder2"),
]
