//
//  ViewController.swift
//  mpp-playground-client-ios
//
//  Created by Khairil Ushan on 8/4/18.
//  Copyright © 2018 Khairil Ushan. All rights reserved.
//

import UIKit
import Mpp

final class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {

    @IBOutlet weak var searchEditText: UITextField!
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var searchButton: UIButton!

    private var projects: [MppProject] = []

    override func viewDidLoad() {
        super.viewDidLoad()
        setupView()
        requestProjectList(keyword: "kotlin")
    }

    @IBAction func onSearchButtonClicked(_ sender: UIButton) {
        guard let keyword = searchEditText.text, !keyword.isEmpty else { return }
        requestProjectList(keyword: keyword)
        searchEditText.resignFirstResponder()
    }

    private func setupView() {
        title = "MPP Playground"
        let textAttributes = [NSAttributedStringKey.foregroundColor: UIColor.white]
        navigationController?.navigationBar.titleTextAttributes = textAttributes
        navigationController?.navigationBar.isTranslucent = false
        navigationController?.navigationBar.barTintColor = UIColor(
            red: 0.15,
            green: 0.25,
            blue: 0.52,
            alpha: 1
        )
        tableView.register(
            ProjectTableViewCell.nib,
            forCellReuseIdentifier: ProjectTableViewCell.identifier
        )
    }

    private func requestProjectList(keyword: String) {
        let interactor = MppInteractor_.createSearchProjectInteractor()
        let params = MppSearchProjectInteractorParams(keyword: keyword)
        interactor.execute(params: params) { [weak self] (result) -> MppStdlibUnit in
            DispatchQueue.main.async { [weak self] in
                if let success = result as? MppResultSuccess,
                   let projects = success.result as? [MppProject] {
                    self?.reloadData(projects)
                } else if let failure = result as? MppResultFailure {
                    print(failure.message)
                }
            }
            return MppStdlibUnit()
        }
    }

    private func reloadData(_ projects: [MppProject]) {
        self.projects = projects
        tableView.reloadData()
    }

    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    func tableView(
        _ tableView: UITableView,
        estimatedHeightForRowAt indexPath: IndexPath
    ) -> CGFloat {
        return ProjectTableViewCell.height
    }

    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return UITableViewAutomaticDimension
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return projects.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(for: indexPath) as ProjectTableViewCell
        cell.bind(with: projects[indexPath.row])
        return cell
    }
}

extension UITableView {
    func dequeueReusableCell<T: UITableViewCell>(for indexPath: IndexPath) -> T where T: ReusableCell {
        return dequeueReusableCell(withIdentifier: T.identifier, for: indexPath) as! T
    }
}

